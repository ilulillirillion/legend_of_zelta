//#include<stdio.h>
#include"SQLAPI.h"
//#include<SQLAPI.h>
//#include"myAPI.h"
//#include <mysql.h>
//#include <mysql/mysql.h>

int main (int argc, char** argv) {
  
  // Create a connection object for interfacing with the database.
  SAConnection connection;
  try {
    connection.Connect ("zelta",              // Database name.
                        "root",               // Database user.
                        "test123",            // Database password.
                        SA_SQLServer_Client); // Database client.
    printf("Database connected.\n");

    // Disconnecting is optional. Autodisconnect occurs in destructor.
    connection.Disconnect();
    printf("Database disconnected.\n");

  }

  catch(SAException & x) {
    
    // Rollback changes on error (may fail)
    try {
      connection.Rollback ();
    } catch (SAException &) {
    }
    printf("%s\n", (const char*)x.ErrText());

  }
  return 0;

};
