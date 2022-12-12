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

void addBook()
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

    string title = "Crime and Punishment";
    string author = "Fyodor Dostoevsky";
    string genre = "Fiction";
    string description = "moral dilemmas";
    string date = "2022-12-11";

    // char *str_title = title.c_str();

    /* Create SQL statement */
    str_sql = "INSERT INTO LIBRARY (ID,TITLE,AUTHOR,GENRE,DESCRIPTION,DATE_ADDED) "
              "VALUES (4, '" +
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

int main(int argc, char *argv[])
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;

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

    /* Create SQL statemednt */
    sql = "CREATE TABLE LIBRARY("
          "ID INT PRIMARY KEY     NOT NULL,"
          "TITLE          TEXT    NOT NULL,"
          "AUTHOR         TEXT    NOT NULL,"
          "GENRE          TEXT    NOT NULL,"
          "DESCRIPTION    TEXT,"
          "DATE_ADDED     TEXT    NOT NULL );";

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

    addBook();

    sqlite3_close(db);
    return 0;
}
