#include"mysql.hpp"
#include<cstdio>
#include<cstdlib>
#include<unistd.h>
#include<string>
#include<iostream>
using namespace std;

int main(void)
{
  string header;
  string body;
  body.resize(10000);

#if 1
  char *info=NULL;
  int lenstr=0;
  lenstr=atoi(getenv("CONTENT_LENGTH"));
  info=(char *)malloc(lenstr+1);
  fread(info,1,lenstr,stdin);
#endif//

  char ret[64];//身份标识
  char user[64];//用户名
  char sw[1024];//交流内容 ---汉字会被转码
  sscanf(info,"ret=%[^&]&usr=%[^&]&swap=%[^&]",ret,user,sw);
  free(info);
  Mysql mysql;
  mysql.ConnectDatabase();

  string sw2 = sw;
  string usr = user;
  if(sw2.size()>0){
    //插入留言 //待审核
    string c = "insert into comment(CID,message) values('"+usr+"','"+sw2+"')";
    mysql.modifydata(c);
  } 
  string rett = ret;
  vector<vector<string> > m;
  mysql.QueryDatabase("select CID,posttime,message from comment where Ispass = 1 order by posttime desc",m);
  string html;
  html.resize(1000);
  //最多显示7条
  for(size_t i = 0; i < m.size()&& i < 7; ++i)
  {
     html +="<p>"+m[i][0]+":"+m[i][2]+"<br/>"+m[i][1]+"<p>";
  }

  if(rett == "ret"){

                body = "<body background=\"http://212.129.243.64/bj.png\"\
                        style=\" background-repeat:no-repeat;background-size:100% 100%;\
                        background-attachment: fixed;\">\
                        <title>学习视频</title>\
                        <div style = \"height:500px;padding-top:305px;\">\
                        <div style=\"background:url(http://212.129.243.64/mokuai.png);\
                        display:block;width:400;float:left;margin-left:30px;\
                        background-repeat: no-repeat;background-size:100% 100%;\">\
                        <form name = \"input1\"\
                        action = \"/cgi-bin/bulletinz.cgi\" method = \"post\" id = \"form1\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+rett+"\" name = \"ret\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+usr+"\" name = \"usr\">\
                        <div style=\"padding-left:110px; padding-top:0px\">\
                        <input type = \"submit\" value= \"公告信息\" style='font-size:40px'>\
                        </div>\
                        </form>\
                        <form name = \"input\" action = \"/cgi-bin/videoz.cgi\" method = \"post\" id = \"form2\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+rett+"\" name = \"ret\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+usr+"\" name = \"usr\">\
                        <div style=\"padding-left:110px; padding-top:10px\">\
                        <input type = \"submit\" value= \"学习视频\" style='font-size:40px'>\
                        </div>\
                        </form>\
                        <form name = \"input\" action = \"/cgi-bin/studyz.cgi\" method = \"post\" id = \"form3\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+rett+"\" name = \"ret\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+usr+"\" name = \"usr\">\
                        <div style=\"padding-left:110px; padding-top:17px\">\
                        <input type = \"submit\" value= \"学习资料\" style='font-size:40px'>\
                        </div>\
                        </form>\
                        <form name = \"input\" action = \"/cgi-bin/swapz.cgi\" method = \"post\" id = \"form4\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+rett+"\" name = \"ret\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+usr+"\" name = \"usr\">\
                        <div style=\"padding-left:110px; padding-top:20px\">\
                        <input type = \"submit\" value= \"学习交流\" style='font-size:40px'>\
                        </div>\
                        </form>\
                        </div>\
                        <div style =\"display:block;float:right; width:50%;\">\
                        <h3>学习交流</h3>\
                        "+html+"\
                        <form name = \"input1\"\
                        action = \"/cgi-bin/swapz.cgi\"  method = \"post\" id = \"form5\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+rett+"\" name = \"ret\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+usr+"\" name = \"usr\">\
                        <div style=\"padding-left:20px; padding-top:0px\">\
                        <input type=\"text\"  name = \"swap\" required=\"\" oninvalid=\"setCustomValidity('你还没有输入内容');\" oninput=\"setCustomValidity('');\">\
                        <input type = \"submit\" value= \"发表\" style='font-size:10px'>\
                        </div>\
                        </form>\
                        </div>\
                        </div>\
                        </body>";
  }
  else{
         body = "<body>\r\n\
                你没有权限\r\n\
                <a href=\"#\" onClick=\"javascript :history.back(-1);\">返回</a>\r\n\
                请先登陆\r\n\
                <a href=\"http://212.129.243.64/\"\">登陆</a>";
  }
  header += "Content-type: text/html;charset=utf-8\r\n\r\n";
  cout<<header+body<<endl;
  return 0;
} 
