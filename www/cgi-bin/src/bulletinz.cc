#include"mysql.hpp"
#include<cstdio>
#include<cstdlib>
#include<unistd.h>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
int main(void)
{
#if 1
  string header;
  //string first_line = "HTTP/1.0 200 OK\n";
  string body;
  body.resize(10000);
  char ret[64];
  char user[64];
  char *info=NULL;
  int lenstr=0;
  /*
   * Get the data by post method from index.html
   */
  lenstr=atoi(getenv("CONTENT_LENGTH"));
  info=(char *)malloc(lenstr+1);
  fread(info,1,lenstr,stdin);
  string data = info;       
  sscanf(info,"ret=%[^&]&usr=%[^&]",ret,user);
  free(info);
#endif
  string usr = user;
  Mysql mysql;
  mysql.ConnectDatabase();
  string rett = ret;
  vector<vector<string> > m;
  mysql.QueryDatabase("message",m);
  //cout<<m[0][0]<<endl;
#if 1
  string html;
  html.resize(1000);
  for(int i = 1; i < 7; ++i)
  {
 html +="<form name = \"input1\"\
                        action = \"/cgi-bin/bulletinzz.cgi\" method = \"post\" id = \"form5\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+rett+"\" name = \"ret\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+m[i][1]+"\" name = \"gg\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+usr+"\" name = \"usr\">\
                        <div style=\"padding-left:20px; padding-top:0px\">\
                        "+m[i][1]+"-------------------"+m[i][2]+"\
                        <input type = \"submit\" value= \"查看\" style='font-size:10px'>\
                        </div>\
                        </form>";
  }
  if(rett == "ret"||rett == "yk"){
    //cout<<"success"<<endl;
#if 0
         body = "<body background=\"http://212.129.243.64/bj.png\"\r\n\
                 style=\" background-repeat:no-repeat;\r\n\
                 background-size:100% 100%;\r\n\
                 background-attachment: fixed;\">\r\n\
                 成功\r\n\
                 <a href=\"http://212.129.243.64/\">hehe</a>\r\n\
                 <a href=\"#\" onClick=\"javascript :history.back(-1);\">返回</a>\r\n\
                 </body>";

#endif

                body = "<body background=\"http://212.129.243.64/bj.png\"\
                        style=\" background-repeat:no-repeat;background-size:100% 100%;\
                        background-attachment: fixed;\">\
                        <title>公告信息</title>\
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
                        <h3>公告信息</h3>\
                        <form name = \"input1\"\
                        action = \"/cgi-bin/bulletinzz.cgi\" method = \"post\" id = \"form5\"style=\"\
                        color: forestgreen\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+rett+"\" name = \"ret\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+m[0][1]+"\" name = \"gg\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+usr+"\" name = \"usr\">\
                        <div style=\"padding-left:20px; padding-top:0px\">\
                        "+m[0][1]+"-------------------"+m[0][2]+"\
                        <input type = \"submit\" value= \"查看\" style='font-size:10px'>\
                        </div>\
                        </form>"+\
/*<form name = \"input1\"\
                        action = \"/cgi-bin/bulletinzz.cgi\" method = \"post\" id = \"form6\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+rett+"\" name = \"ret\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+m[1][0]+"\" name = \"gg\">\
                        <div style=\"padding-left:20px; padding-top:0px\">\
                        "+m[1][0]+"-------------------"+m[1][1]+"\
                        <input type = \"submit\" value= \"查看\" style='font-size:10px'>\
                        </div>\
                        </form>\
<form name = \"input1\"\
                        action = \"/cgi-bin/bulletinzz.cgi\" method = \"post\" id = \"form7\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+rett+"\" name = \"ret\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+m[2][0]+"\" name = \"gg\">\
                        <div style=\"padding-left:20px; padding-top:0px\">\
                        "+m[2][0]+"-------------------"+m[2][1]+"\
                        <input type = \"submit\" value= \"查看\" style='font-size:10px'>\
                        </div>\
                        </form>\
<form name = \"input1\"\
                        action = \"/cgi-bin/bulletinzz.cgi\" method = \"post\" id = \"form8\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+rett+"\" name = \"ret\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+m[3][0]+"\" name = \"gg\">\
                        <div style=\"padding-left:20px; padding-top:0px\">\
                        "+m[3][0]+"-------------------"+m[3][1]+"\
                        <input type = \"submit\" value= \"查看\" style='font-size:10px'>\
                        </div>\
                        </form>*/
                        html+"\
                        </div>\
                        </div>\
                        </body>";







































  }
  else{
         body = "<body>\r\n\
                你没有权限查看此文件\r\n\
                <a href=\"#\" onClick=\"javascript :history.back(-1);\">返回</a><br/>\r\n\
                请先登陆\r\n\
                <a href=\"http://212.129.243.64/\"\">登陆</a>";
  }
  header += "Content-type: text/html;charset=utf-8\r\n\r\n";
  cout<<header+body<<endl;
#endif
  return 0;
} 
