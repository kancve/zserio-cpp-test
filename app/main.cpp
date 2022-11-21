#include <iostream>
#include "sql_databases/db_with_relocation/EuropeDb.h"

int main() {
    std::cout << "Hello zserio !" << std::endl;
    sql_databases::db_with_relocation::EuropeDb db("D:/zserio.sqlite");
    db.createSchema();

    return 0;
}