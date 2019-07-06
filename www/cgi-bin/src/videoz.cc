#include"mysql.hpp"
#include<cstdio>
#include<cstdlib>
#include<unistd.h>
#include<string>
#include<iostream>
#include<vector>
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
#endif//获取请求数据

  char ret[64];//身份标识
  char user[64];//用户名
  sscanf(info,"ret=%[^&]&usr=%[^&]",ret,user);//解析数据
  free(info);

  vector<vector<string> > m;
  Mysql mysql;
  mysql.ConnectDatabase();
  string qu = "select lesson,content from video";
  mysql.QueryDatabase(qu,m);

  string html;
  html.resize(1000);
  for(size_t i = 0;i < m.size(); ++i)
  {
      html += "<p>"+m[i][0]+"<p><video width=\"600\" height=\"300\" controls>\
              <source src=\"../"+m[i][1]+"\" type=\"video/mp4\">\
              </video>";
  }

  string rett = ret;
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
                        <input type=\"text\" style=\"display:none;\" value=\""+user+"\" name = \"usr\">\
                        <div style=\"padding-left:110px; padding-top:0px\">\
                        <input type = \"submit\" value= \"公告信息\" style='font-size:40px'>\
                        </div>\
                        </form>\
                        <form name = \"input\" action = \"/cgi-bin/videoz.cgi\" method = \"post\" id = \"form2\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+rett+"\" name = \"ret\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+user+"\" name = \"usr\">\
                        <div style=\"padding-left:110px; padding-top:10px\">\
                        <input type = \"submit\" value= \"学习视频\" style='font-size:40px'>\
                        </div>\
                        </form>\
                        <form name = \"input\" action = \"/cgi-bin/studyz.cgi\" method = \"post\" id = \"form3\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+rett+"\" name = \"ret\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+user+"\" name = \"usr\">\
                        <div style=\"padding-left:110px; padding-top:17px\">\
                        <input type = \"submit\" value= \"学习资料\" style='font-size:40px'>\
                        </div>\
                        </form>\
                        <form name = \"input\" action = \"/cgi-bin/swapz.cgi\" method = \"post\" id = \"form4\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+rett+"\" name = \"ret\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+user+"\" name = \"usr\">\
                        <div style=\"padding-left:110px; padding-top:20px\">\
                        <input type = \"submit\" value= \"学习交流\" style='font-size:40px'>\
                        </div>\
                        </form>\
                        </div>\
                        <div style =\"display:block;float:right; width:50%;\">\
                        <h3>学习视频</h3>\
                        "+html+"\
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
