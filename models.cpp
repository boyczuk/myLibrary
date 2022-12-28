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

int makeTable(int argc, char *argv[])
{
    // Change to main when creating new table
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    // char *sql;
    string str_sql;

    /* Open database */
    rc = sqlite3_open("library.db", &db);

    if (rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return (0);
    }
    else
    {
        fprintf(stdout, "Opened database successfully\n");
    }

    /* Create SQL statement */
    str_sql = "CREATE TABLE LIBRARY("
              "TITLE          TEXT    NOT NULL,"
              "AUTHOR         TEXT    NOT NULL,"
              "GENRE          TEXT    NOT NULL,"
              "STATUS         TEXT    NOT NULL,"
              "DATE_ADDED     TEXT    NOT NULL );";

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
        fprintf(stdout, "Table created successfully\n");
    }
    sqlite3_close(db);
    return 0;
}

void addBook(string title, string author, string genre, string status, string date)
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

    // change ID value to rows in db
    /* Create SQL statement */
    str_sql = "INSERT INTO LIBRARY (TITLE,AUTHOR,GENRE,STATUS,DATE_ADDED) "
              "VALUES ('" +
              title + "', '" + author + "', '" + genre + "', '" + status + "', '" + date + "' ); ";

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
        fprintf(stdout, "Book added!\n");
    }
    sqlite3_close(db);
    return;
}

void removeBook(string title, string author)
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    // char *sql;
    string str_sql;
    const char *data = "Callback function called";

    /* Open database */
    rc = sqlite3_open("library.db", &db);

    /* Create merged SQL statement */
    str_sql = "DELETE from LIBRARY where TITLE='" + title + "'; "
                                                            "SELECT * from LIBRARY";

    const char *sql = str_sql.c_str();

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void *)data, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "Removed Successfully\n");
    }
    sqlite3_close(db);
}

void displayBooks()
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    //char *sql;
    string str_sql;
    const char *data = "Callback function called";

    /* Open database */
    rc = sqlite3_open("library.db", &db);

    if (rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    }
    else
    {
        fprintf(stderr, "============myLibary===========\n");
    }

    const char *sql = str_sql.c_str();

    /* Create SQL statement */
    sql = "SELECT * from LIBRARY";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void *)data, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    sqlite3_close(db);
}