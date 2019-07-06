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
#endif//获取请求


  char Who[64];//用户/管理员
  char user[64];//用户名
  char passwd[64];//用户输入的密码

  sscanf(info,"Who=%[^&]&username=%[^&]&password=%[^&]",Who,user,passwd);//解析数据
  free(info);

  string ret = "ret";//身份标识
  string username = user;
  string password = passwd;
  string who = Who;

  Mysql mysql;
  mysql.ConnectDatabase();
  vector<vector<string> > m;
  string qu;
  qu = "select * from user where username = '" + username+"'";
  mysql.QueryDatabase(qu,m);
  //m.size()表示有数据，不判断会导致越界
  if(m.size()&& password == m[0][1] &&who == "Common"&& m[0][2] > "0"){

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
  }
  else if(m.size()&&password== m[0][1]&&who=="Admin"){
                      //管理员
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
        //密码错误
         body = "<body>\r\n\
                用户名或密码错误\r\n\
                <a href=\"#\" onClick=\"javascript :history.back(-1);\">返回</a>\r\n";
  }

  header += "Content-type: text/html;charset=utf-8\r\n\r\n";//必须加这句
  cout<<header+body<<endl;
  return 0;
} 
