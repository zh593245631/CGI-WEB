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
  string header;
  //string first_line = "HTTP/1.0 200 OK\n";
  string body;
  body.resize(10000);
  char name[64];
  char Who[64];
  char ret[64];
  char So[64];
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
  sscanf(info,"Who=%[^&]&ret=%[^&]&name=%[^&]&so=%[^&]&usr=%[^&]",Who,ret,name,So,user);
  free(info);
  string rett = ret;
  string m = name;
  string who = Who;
  string so = So;
  vector<vector<string> > v;
  Mysql mysql;
  mysql.ConnectDatabase();
  string Quer1 = "select content, pDate,visit  from resource where "+who+"= '"+m+"' order by "+so+" desc";
  mysql.QueryDatabase3(Quer1,v);
  string html;
  html.resize(1000);
  size_t line = v.size();
  if(v.size() != 0)
  html += "<div id=\"page1\" style=\"display:block;\">时间:"+v[0][1]+"<br/>"+v[0][0]+"<br/>"+v[0][2] +"</div>";
  for(size_t i = 1; i < v.size(); ++i){
      html += "<div id=\"page";
      html += to_string(i+1);
      html += "\" style=\"display:none;\">时间:"+v[i][1]+"<br/>"+v[i][0]+"<br/>"+v[i][2] +"</div>";
  }
  for(size_t i = 1; i < v.size(); ++i)
  {
     html +="<a href=\"javascript:showpage(";
     html += to_string(i); 
     html += ");\">第";
     html += to_string(i);
     html += "页</a>";
  }
  if(rett == "ret"|| rett == "yk"){
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
#if 1

                body = "<body background=\"http://212.129.243.64/bj.png\"\
                        style=\" background-repeat:no-repeat;background-size:100% 100%;\
                        background-attachment: fixed;\">\
                        <title>学习资料查询</title>\
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
                        <h3>学习资料</h3>\
                        "+html+"\
<script>\
function showpage(page){\
  for(var i=1;i<="+to_string(line)+";i++) {\
    if (page==i){\
      document.getElementById(\"page\"+page).style.display=\"block\";\
    } else {\
      document.getElementById(\"page\"+i).style.display=\"none\";\
    }\
  }\
}\
</script>\
                        <div id=div1></div>\
                        </div>\
                        </div>\
                        </body>";





























#endif
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
  return 0;
} 
