#pragma once
#include <stdio.h>
#include <mysql/mysql.h>   
#include<string>
#include<vector>
using namespace std;

class Mysql
{
public:
    Mysql()
    {
      mysql_init(&mysql); 
    }
    //连接数据库
    bool ConnectDatabase(
      const char host[] = "127.0.0.1",
      const char user[] = "root",
      const char passwd[] = "qwerdf123",
      const char db[] = "db",
      unsigned int port = 3306,
      const char *unix_socket = NULL,
      unsigned long client_flag = 0
      ){
      //Gets or initializes a MYSQL structure
      // Connects to a MySQL server
      /*A MYSQL* connection handler if the connection was successful, 
       NULL if the connection was unsuccessful. For a successful connection, 
       the return value is the same as the value of the first parameter.*/
      if (mysql_real_connect(&mysql, host, user, passwd, db, port, unix_socket, client_flag)){
                 return true;
      }
      else{
             /*const char *mysql_error(MYSQL *mysql)
               Returns the error message for the most recently invoked MySQL function
               A null-terminated character string that describes the error. 
               An empty string if no error occurred.*/
                 return false;
      }
     }

     ~Mysql()
     {
        mysql_free_result(res);
        mysql_close(&mysql);
     }

//查询数据
 bool QueryDatabase(const string& query, vector<vector<string> > & data){
   
      //设置编码格式
       mysql_query(&mysql, "SET NAMES UTF8"); 
       if (mysql_query(&mysql, query.c_str())){
              return false;
       }
       res = mysql_store_result(&mysql);
       if (!res){
            return false;
       }
       //获取行数
      long long line = mysql_affected_rows(&mysql);
      // 获取列数
      int ll = mysql_num_fields(res);
      data = vector<vector<string> >(line,vector<string>(ll,""));
#if 0
      //存储字段信息
         char *str_field[32];  
    
      //获取字段名
         for (int i = 0; i < j; i++){ 
           str_field[i] = mysql_fetch_field(res)->name;
         }
     //打印字段
          for (int i = 0; i < j; i++)  
                 printf("%10s\t", str_field[i]);
          printf("\n");
#endif

         MYSQL_ROW column;   //数据行的列
         int i = 0;
         while(column = mysql_fetch_row(res)){
           for(int j = 0; j < ll; ++j){
             data[i][j] = column[j];
           }
           ++i;
        }
      return true;

}
//修改数据
bool modifydata(const string& query){

   mysql_query(&mysql, "SET NAMES UTF8"); 
   if (mysql_query(&mysql, query.c_str())) {
       return false;
    }
   else{
       return true;
    }
}

private:
    MYSQL mysql;
    MYSQL_RES *res;     //行的一个查询结果集
};
