package sql_databases.db_with_relocation;

struct Tile
{
    uint8   version;
    uint8   data;
};

sql_table CountryMapTable
{
    /** Refer to the definition of SmartLayerMetadaTable (NDS.Live), just to reproduce the wrong scene.*/
    int32   tileId sql "PRIMARY KEY DEFAULT 0 NOT NULL";
    Tile    tile;
    
    sql("check tileId = 0");
};

sql_database EuropeDb
{
    CountryMapTable germany;
};

sql_database AmericaDb
{
    CountryMapTable usa;
    CountryMapTable canada;
    CountryMapTable slovakia;
    CountryMapTable czechia;
};
