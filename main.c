#include <iostream>
#include <string>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

int main() {
    sql::Driver *driver;
    sql::Connection *con = NULL;
    sql::Statement *stmt;
    sql::ResultSet *res;

    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "root", "");
    con->setSchema("test");
    if(con != NULL)
        cout << "Connected success!" << endl;
    else {
        cout << "Connected failed!" << endl;         
        return -1;     
    }         
    // string sql = "insert into user (id, name, age) values (5, 'duke', 37);";    
    string sql = "select * from user;";    
    stmt = con->createStatement();
    res = stmt->executeQuery(sql);
    while(res->next()) {
    	cout <<  res->getString("name") << "  " << endl;
    }
    delete res;
    delete stmt;
    delete con;
    return 0;
}

