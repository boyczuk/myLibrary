#include <iostream>
#include <sqlite3.h>
#include <string>
#include <stdlib.h>

using namespace std;

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

void addBook(string title, string author, string genre, string description, string date)
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    string str_sql;

    /* Open database */
    rc = sqlite3_open("library.db", &db);

    if (rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return;
    }
    else
    {
        fprintf(stderr, "Opened database successfully\n");
    }

    // change ID value to rows in db    
    /* Create SQL statement */
    str_sql = "INSERT INTO LIBRARY (ID,TITLE,AUTHOR,GENRE,DESCRIPTION,DATE_ADDED) "
              "VALUES (7, '" +
              title + "', '" + author + "', '" + genre + "', '" + description + "', '" + date + "' ); ";

    const char *sql = str_sql.c_str();

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "Records created successfully\n");
    }
    sqlite3_close(db);
    return;
}

void removeBook() {
    
}

void displayBooks(){

}