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
  //string first_line = "HTTP/1.0 200 OK\n";
  string body;
  body.resize(10000);
  char Who[64];
  char user[64];
  char passwd[64];
  char *info=NULL;
  int lenstr=0;
  /*
   * Get the data by post method from index.html
   */
  lenstr=atoi(getenv("CONTENT_LENGTH"));
  info=(char *)malloc(lenstr+1);
  fread(info,1,lenstr,stdin);
  string data = info;       
  sscanf(info,"Who=%[^&]&username=%[^&]&password=%[^&]",Who,user,passwd);
  free(info);
  string ret = "ret";
  string username = user;
  string password = passwd;
  string who = Who;
  Mysql mysql;
  mysql.ConnectDatabase();
  string dbpass;
  string access;
  //select * from user which username=root;
  mysql.QueryDatabase("user","password","username",username,dbpass);
  mysql.QueryDatabase("user","access","username",username,access);
  if( password == dbpass &&who == "Common"&& access > "0"){
    //cout<<"success"<<endl;
    sleep(1);
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
#if 1

                body = "<body background=\"http://212.129.243.64/bj.png\"\
                        style=\" background-repeat:no-repeat;background-size:100% 100%;\
                        background-attachment: fixed;\">\
                        <title>首页</title>\
                        <div style = \"height:500px;padding-top:305px;\">\
                        <div style=\"background:url(http://212.129.243.64/mokuai.png);\
                        display:block;width:400;float:left;margin-left:30px;\
                        background-repeat: no-repeat;background-size:100% 100%;\">\
                        <form name = \"input1\"\
                        action = \"/cgi-bin/bulletinz.cgi\" method = \"post\" id = \"form1\">\"\
                        <input type=\"text\" style=\"display:none;\" value=\""+ret+"\" name = \"ret\">\
                        <input type=\"text\"style=\"display:none;\" value=\""+username+"\" name = \"usr\">\
                        <div style=\"padding-left:110px; padding-top:0px\">\
                        <input type = \"submit\" value= \"公告信息\" style='font-size:40px'>\
                        </div>\
                        </form>\
                        <form name = \"input\" action = \"/cgi-bin/videoz.cgi\" method = \"post\" id = \"form2\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+ret+"\" name = \"ret\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+username+"\" name = \"usr\">\
                        <div style=\"padding-left:110px; padding-top:10px\">\
                        <input type = \"submit\" value= \"学习视频\" style='font-size:40px'>\
                        </div>\
                        </form>\
                        <form name = \"input\" action = \"/cgi-bin/studyz.cgi\" method = \"post\" id = \"form3\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+ret+"\" name = \"ret\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+username+"\" name = \"usr\">\
                        <div style=\"padding-left:110px; padding-top:17px\">\
                        <input type = \"submit\" value= \"学习资料\" style='font-size:40px'>\
                        </div>\
                        </form>\
                        <form name = \"input\" action = \"/cgi-bin/swapz.cgi\" method = \"post\" id = \"form4\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+ret+"\" name = \"ret\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+username+"\" name = \"usr\">\
                        <div style=\"padding-left:110px; padding-top:20px\">\
                        <input type = \"submit\" value= \"学习交流\" style='font-size:40px'>\
                        </div>\
                        </form>\
                        </div>\
                        <div style =\"display:block;float:right; width:50%;\">\
                        <h3>简介</h3>\
                        <p>网上信学习流平台是一个虚拟网络学习的社区环境，它为学习者提供了学习和交流的平台</p>\
                        </div>\
                        </div>\
                        </body>";
#endif
  }
  else if(password==dbpass&&who=="Admin"){
                      body = "<form name = \"input\" action = \"/cgi-bin/manger.cgi\" \
                      method = \"post\" id = \"form4\">\
                      <input type=\"text\" style=\"display:none;\" value=\""+ret+"\" name = \"ret\">\
                      <input type=\"text\" style=\"display:none;\" value=\""+username+"\" name = \"usr\">\
                      <div style=\"padding-left:110px; padding-top:20px\">\
                      <input type = \"submit\" value= \"进入管理系统\" style='font-size:40px'>\
                      </div>\
                      </form>";
 }

























  else{

         body = "<body>\r\n\
                用户名或密码错误\r\n\
                <a href=\"#\" onClick=\"javascript :history.back(-1);\">返回</a>\r\n";
  }
  header += "Content-type: text/html;charset=utf-8\r\n\r\n";
  cout<<header+body<<endl;
  return 0;
} 
