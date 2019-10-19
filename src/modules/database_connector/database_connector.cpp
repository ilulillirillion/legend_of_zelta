// TODO: Add support for additional databases.
// TODO:  Replace auto_ptrs with unique_ptrs?
//        http://www.cplusplus.com/reference/memory/auto_ptr/
// TODO: Replace cout calls with logger integration.

#include <sstream>
#include <stdexcept>

// FIXME: Find a better way to include these.
#include "mysql_connection.h"
#include "cppconn/connection.h"
#include "cppconn/driver.h"
#include "cppconn/exception.h"
#include "cppconn/resultset.h"
#include "cppconn/statement.h"
#include "cppconn/prepared_statement.h"

#define DEFAULT_STATEMENT "SELECT 1"
// TODO: Add error handling if these env variables are not defined.
#define ENV_URI std::getenv("ZELTA_DBCON_URI")
#define ENV_USERNAME std::getenv("ZELTA_DBCON_USERNAME")
#define ENV_PASSWORD std::getenv("ZELTA_DBCON_PASSWORD")
#define ENV_DATABASE std::getenv("ZELTA_DBCON_DATABASE")

//FIXME: Get rid of this and namespace dependencies instead.
using namespace std;

// TODO: Is argv the best solution here?
int main(int argc, const char **argv) {
  
  // Handle arguments (if they exist), fall back to environment variables.
  const string statement_string(argc >= 2 ? argv[1] : DEFAULT_STATEMENT); 
  const string uri(argc >= 3 ? argv[2] : ENV_URI);
  const string username(argc >= 4 ? argv[3] : ENV_USERNAME);
  const string password(argc >= 5 ? argv[4] : ENV_PASSWORD);
  const string database(argc >= 6 ? argv[5] : ENV_DATABASE);

  cout << "Running a database operation." << endl;
  cout << endl;

  try {

    // Create an SQL driver to enable MySQL connections.
    sql::Driver* driver = get_driver_instance();

    // Create a connection instance to interface with the MySQL database.
    // FIXME: Over 80 chars.
    std::auto_ptr<sql::Connection> connection(driver->connect(uri, username, password));

    // Tell the connection which database to use.
    connection->setSchema(database);

    // Test database connectivity with a 60 second timeout.
    connection->isValid();

    // Create a statement object to send to SQL.
    std::auto_ptr<sql::Statement> statement(connection->createStatement());

    // Execute the statement (run in SQL), using the statement_string
    // variable.
    statement->execute(statement_string);

  /*
    SQLException throws three different exceptions:

    - sql::MethodNotImplementedException (derived from sql::SQLException)
    - sql::InvalidArgumentException (derived from sql::SQLException)
    - sql::SQLException (derived from std::runtime_error)
  */
  } catch (sql::SQLException &e) {
    
    // Log various details about the SQL exception.
    cout << "# ERROR: SQLException in " << __FILE__;
    cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
    /* what() (derived from std::runtime_error) fetches error message */
    cout << "# ERROR: " << e.what();
    cout << " (MySQL error code: " << e.getErrorCode();
    cout << ", SQLState: " << e.getSQLState() << " )" << endl;
   
    // Return an abstraction representing a local system standard error code. 
    return EXIT_FAILURE;

  }

  cout << "Done." << endl;
  return EXIT_SUCCESS;

}
