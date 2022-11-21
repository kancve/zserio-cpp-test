/**
 * Automatically generated by Zserio C++ extension version 2.8.0.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, sourcesAmalgamation, stdAllocator.
 */

#ifndef SQL_DATABASES_DB_WITH_RELOCATION_COUNTRY_MAP_TABLE_H
#define SQL_DATABASES_DB_WITH_RELOCATION_COUNTRY_MAP_TABLE_H

#include <memory>
#include <sqlite3.h>
#include <zserio/Vector.h>
#include <zserio/ArrayTraits.h>
#include <zserio/String.h>
#include <zserio/AllocatorHolder.h>
#include <zserio/Span.h>
#include <zserio/StringView.h>
#include <zserio/SqliteConnection.h>
#include <zserio/SqliteFinalizer.h>
#include <zserio/OptionalHolder.h>
#include <zserio/ArrayTraits.h>
#include <zserio/Types.h>

#include <sql_databases/db_with_relocation/Tile.h>

namespace sql_databases
{
namespace db_with_relocation
{

class CountryMapTable : public ::zserio::AllocatorHolder<::std::allocator<uint8_t>>
{
public:
    class Row
    {
    public:
        int32_t getTileId() const;
        void setTileId(int32_t tileId_);
        void resetTileId();
        bool isTileIdSet() const;

        ::sql_databases::db_with_relocation::Tile& getTile();
        const ::sql_databases::db_with_relocation::Tile& getTile() const;
        void setTile(const ::sql_databases::db_with_relocation::Tile& tile_);
        void setTile(::sql_databases::db_with_relocation::Tile&& tile_);
        void resetTile();
        bool isTileSet() const;

        void initializeOffsets();

    private:
        ::zserio::InplaceOptionalHolder<int32_t> m_tileId_;
        ::zserio::InplaceOptionalHolder<::sql_databases::db_with_relocation::Tile> m_tile_;
    };

    class Reader : public ::zserio::AllocatorHolder<::std::allocator<uint8_t>>
    {
    public:
        ~Reader() = default;

        Reader(const Reader&) = delete;
        Reader& operator=(const Reader&) = delete;

        Reader(Reader&&) = default;
        Reader& operator=(Reader&&) = delete;

        bool hasNext() const noexcept;
        Row next();

    private:
        explicit Reader(::zserio::SqliteConnection& db, const ::zserio::string<>& sqlQuery, const allocator_type& allocator = allocator_type());
        friend class CountryMapTable;

        void makeStep();

        ::std::unique_ptr<sqlite3_stmt, ::zserio::SqliteFinalizer> m_stmt;
        int m_lastResult;
    };

    CountryMapTable(::zserio::SqliteConnection& db, ::zserio::StringView tableName,
            ::zserio::StringView attachedDbName = ::zserio::StringView(),
            const allocator_type& allocator = allocator_type());
    CountryMapTable(::zserio::SqliteConnection& db, ::zserio::StringView tableName, const allocator_type& allocator);

    ~CountryMapTable() = default;

    CountryMapTable(const CountryMapTable&) = delete;
    CountryMapTable& operator=(const CountryMapTable&) = delete;

    CountryMapTable(CountryMapTable&&) = delete;
    CountryMapTable& operator=(CountryMapTable&&) = delete;

    void createTable();
    void deleteTable();

    Reader createReader(::zserio::StringView condition = ::zserio::StringView()) const;
    void write(::zserio::Span<Row> rows);
    void update(Row& row, ::zserio::StringView whereCondition);

private:
    void writeRow(Row& row, sqlite3_stmt& statement);

    void appendCreateTableToQuery(::zserio::string<>& sqlQuery) const;

    void appendTableNameToQuery(::zserio::string<>& sqlQuery) const;

    ::zserio::SqliteConnection& m_db;
    ::zserio::StringView m_name;
    ::zserio::StringView m_attachedDbName;
};

} // namespace db_with_relocation
} // namespace sql_databases

#endif // SQL_DATABASES_DB_WITH_RELOCATION_COUNTRY_MAP_TABLE_H