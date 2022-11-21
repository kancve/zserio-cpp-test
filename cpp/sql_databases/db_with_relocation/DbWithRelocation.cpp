/**
 * Automatically generated by Zserio C++ extension version 2.8.0.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, sourcesAmalgamation, stdAllocator.
 */

#include <zserio/StringConvertUtil.h>
#include <zserio/CppRuntimeException.h>
#include <zserio/HashCodeUtil.h>
#include <zserio/BitPositionUtil.h>
#include <zserio/BitSizeOfCalculator.h>
#include <zserio/BitFieldUtil.h>

#include <sql_databases/db_with_relocation/Tile.h>

namespace sql_databases
{
namespace db_with_relocation
{

Tile::Tile(const allocator_type&) noexcept :
        m_version_(uint8_t()),
        m_data_(uint8_t())
{
}

Tile::Tile(::zserio::BitStreamReader& in, const allocator_type&) :
        m_version_(readVersion(in)),
        m_data_(readData(in))
{
}

Tile::Tile(::zserio::PackingContextNode& contextNode, ::zserio::BitStreamReader& in, const allocator_type&) :
        m_version_(readVersion(contextNode, in)),
        m_data_(readData(contextNode, in))
{
}

Tile::Tile(::zserio::PropagateAllocatorT,
        const Tile& other, const allocator_type& allocator) :
        m_version_(::zserio::allocatorPropagatingCopy(other.m_version_, allocator)),
        m_data_(::zserio::allocatorPropagatingCopy(other.m_data_, allocator))
{
}

uint8_t Tile::getVersion() const
{
    return m_version_;
}

void Tile::setVersion(uint8_t version_)
{
    m_version_ = version_;
}

uint8_t Tile::getData() const
{
    return m_data_;
}

void Tile::setData(uint8_t data_)
{
    m_data_ = data_;
}

void Tile::createPackingContext(::zserio::PackingContextNode& contextNode)
{
    contextNode.createChild().createContext();
    contextNode.createChild().createContext();
}

void Tile::initPackingContext(::zserio::PackingContextNode& contextNode) const
{
    contextNode.getChildren().at(0).getContext().init(
            ::zserio::StdIntArrayTraits<uint8_t>(), m_version_);
    contextNode.getChildren().at(1).getContext().init(
            ::zserio::StdIntArrayTraits<uint8_t>(), m_data_);
}

size_t Tile::bitSizeOf(size_t bitPosition) const
{
    size_t endBitPosition = bitPosition;

    endBitPosition += UINT8_C(8);
    endBitPosition += UINT8_C(8);

    return endBitPosition - bitPosition;
}

size_t Tile::bitSizeOf(::zserio::PackingContextNode& contextNode, size_t bitPosition) const
{
    size_t endBitPosition = bitPosition;

    endBitPosition += contextNode.getChildren().at(0).getContext().bitSizeOf(
            ::zserio::StdIntArrayTraits<uint8_t>(), m_version_);
    endBitPosition += contextNode.getChildren().at(1).getContext().bitSizeOf(
            ::zserio::StdIntArrayTraits<uint8_t>(), m_data_);

    return endBitPosition - bitPosition;
}

size_t Tile::initializeOffsets(size_t bitPosition)
{
    size_t endBitPosition = bitPosition;

    endBitPosition += UINT8_C(8);
    endBitPosition += UINT8_C(8);

    return endBitPosition;
}

size_t Tile::initializeOffsets(::zserio::PackingContextNode& contextNode, size_t bitPosition)
{
    size_t endBitPosition = bitPosition;

    endBitPosition += contextNode.getChildren().at(0).getContext().bitSizeOf(
            ::zserio::StdIntArrayTraits<uint8_t>(), m_version_);
    endBitPosition += contextNode.getChildren().at(1).getContext().bitSizeOf(
            ::zserio::StdIntArrayTraits<uint8_t>(), m_data_);

    return endBitPosition;
}

bool Tile::operator==(const Tile& other) const
{
    if (this != &other)
    {
        return
                (m_version_ == other.m_version_) &&
                (m_data_ == other.m_data_);
    }

    return true;
}

uint32_t Tile::hashCode() const
{
    uint32_t result = ::zserio::HASH_SEED;

    result = ::zserio::calcHashCode(result, m_version_);
    result = ::zserio::calcHashCode(result, m_data_);

    return result;
}

void Tile::write(::zserio::BitStreamWriter& out) const
{
    out.writeBits(m_version_, UINT8_C(8));
    out.writeBits(m_data_, UINT8_C(8));
}

void Tile::write(::zserio::PackingContextNode& contextNode, ::zserio::BitStreamWriter& out) const
{
    contextNode.getChildren().at(0).getContext().write(
            ::zserio::StdIntArrayTraits<uint8_t>(), out, m_version_);
    contextNode.getChildren().at(1).getContext().write(
            ::zserio::StdIntArrayTraits<uint8_t>(), out, m_data_);
}

uint8_t Tile::readVersion(::zserio::BitStreamReader& in)
{
    return static_cast<uint8_t>(in.readBits(UINT8_C(8)));
}

uint8_t Tile::readVersion(::zserio::PackingContextNode& contextNode, ::zserio::BitStreamReader& in)
{
    return contextNode.getChildren().at(0).getContext().read(::zserio::StdIntArrayTraits<uint8_t>(), in);
}

uint8_t Tile::readData(::zserio::BitStreamReader& in)
{
    return static_cast<uint8_t>(in.readBits(UINT8_C(8)));
}

uint8_t Tile::readData(::zserio::PackingContextNode& contextNode, ::zserio::BitStreamReader& in)
{
    return contextNode.getChildren().at(1).getContext().read(::zserio::StdIntArrayTraits<uint8_t>(), in);
}

} // namespace db_with_relocation
} // namespace sql_databases

/**
 * Automatically generated by Zserio C++ extension version 2.8.0.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, sourcesAmalgamation, stdAllocator.
 */

#include <zserio/SqliteException.h>

#include <sql_databases/db_with_relocation/EuropeDb.h>

namespace sql_databases
{
namespace db_with_relocation
{

EuropeDb::EuropeDb(const ::zserio::string<>& dbFileName, const TRelocationMap& tableToDbFileNameRelocationMap,
        const allocator_type& allocator) :
        ::zserio::AllocatorHolder<allocator_type>(allocator),
        m_tableToAttachedDbNameRelocationMap(allocator)
{
    sqlite3 *internalConnection = nullptr;
    const int sqliteOpenMode = SQLITE_OPEN_URI | SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE;
    const int result = sqlite3_open_v2(dbFileName.c_str(), &internalConnection, sqliteOpenMode, nullptr);
    m_db.reset(internalConnection, ::zserio::SqliteConnection::INTERNAL_CONNECTION);
    if (result != SQLITE_OK)
    {
        throw ::zserio::SqliteException("EuropeDb::open(): can't open DB ") << dbFileName.c_str() << ": " <<
                ::zserio::SqliteErrorCode(result);
    }

    ::std::map<::zserio::StringView, ::zserio::string<>> dbFileNameToAttachedDbNameMap(
            get_allocator_ref());
    for (const auto& relocation : tableToDbFileNameRelocationMap)
    {
        const ::zserio::string<>& tableName = relocation.first;
        const ::zserio::string<>& fileName = relocation.second;
        auto attachedDbIt = dbFileNameToAttachedDbNameMap.find(fileName);
        if (attachedDbIt == dbFileNameToAttachedDbNameMap.end())
        {
            ::zserio::string<> attachedDbName =
                    ::zserio::stringViewToString(databaseName(), get_allocator_ref()) + "_" + tableName;
            attachDatabase(fileName, attachedDbName);
            attachedDbIt = dbFileNameToAttachedDbNameMap.emplace(fileName, ::std::move(attachedDbName)).first;
        }
        m_tableToAttachedDbNameRelocationMap.emplace(
                ::zserio::string<>(tableName, get_allocator_ref()),
                ::zserio::string<>(attachedDbIt->second, get_allocator_ref()));
    }

    initTables();
}

EuropeDb::EuropeDb(const ::zserio::string<>& fileName, const allocator_type& allocator) :
        EuropeDb(fileName, TRelocationMap(allocator), allocator)
{}

EuropeDb::EuropeDb(sqlite3* externalConnection, const TRelocationMap& tableToAttachedDbNameRelocationMap,
        const allocator_type& allocator) :
        ::zserio::AllocatorHolder<allocator_type>(allocator),
        m_tableToAttachedDbNameRelocationMap(tableToAttachedDbNameRelocationMap, allocator)
{
    m_db.reset(externalConnection, ::zserio::SqliteConnection::EXTERNAL_CONNECTION);
    initTables();
}

EuropeDb::EuropeDb(sqlite3* externalConnection, const allocator_type& allocator) :
        EuropeDb(externalConnection, TRelocationMap(allocator), allocator)
{}

EuropeDb::~EuropeDb()
{
    detachDatabases();
}

::zserio::SqliteConnection& EuropeDb::connection() noexcept
{
    return m_db;
}

::sql_databases::db_with_relocation::CountryMapTable& EuropeDb::getGermany() noexcept
{
    return *m_germany_;
}

void EuropeDb::createSchema()
{
    const bool wasTransactionStarted = m_db.startTransaction();

    m_germany_->createTable();

    m_db.endTransaction(wasTransactionStarted);
}

void EuropeDb::createSchema(const ::std::set<::zserio::string<>>&)
{
    createSchema();
}

void EuropeDb::deleteSchema()
{
    const bool wasTransactionStarted = m_db.startTransaction();

    m_germany_->deleteTable();

    m_db.endTransaction(wasTransactionStarted);
}

::zserio::StringView EuropeDb::databaseName() noexcept
{
    return ::zserio::makeStringView("EuropeDb");
}

::zserio::StringView EuropeDb::tableNameGermany() noexcept
{
    return ::zserio::makeStringView("germany");
}

const ::std::array<::zserio::StringView, 1>& EuropeDb::tableNames() noexcept
{
    static const ::std::array<::zserio::StringView, 1> names =
    {
        tableNameGermany()
    };

    return names;
}

void EuropeDb::initTables()
{
    static ::zserio::StringView EMPTY_STR = ::zserio::StringView();
    auto relocationIt = m_tableToAttachedDbNameRelocationMap.find(
            ::zserio::stringViewToString(tableNameGermany(), get_allocator_ref()));
    m_germany_ = ::zserio::allocate_unique<::sql_databases::db_with_relocation::CountryMapTable>(
            get_allocator_ref(), this->m_db, tableNameGermany(),
            relocationIt != m_tableToAttachedDbNameRelocationMap.end() ? relocationIt->second : EMPTY_STR,
            get_allocator_ref());
}

void EuropeDb::attachDatabase(::zserio::StringView fileName, ::zserio::StringView attachedDbName)
{
    ::zserio::string<> sqlQuery(get_allocator_ref());
    sqlQuery += "ATTACH DATABASE '";
    sqlQuery += fileName;
    sqlQuery += "' AS ";
    sqlQuery += attachedDbName;

    m_db.executeUpdate(sqlQuery);

    m_attachedDbList.push_back(::zserio::stringViewToString(attachedDbName, get_allocator_ref()));
}

void EuropeDb::detachDatabases()
{
    for (const auto& attachedDb : m_attachedDbList)
    {
        ::zserio::string<> sqlQuery(get_allocator_ref());
        sqlQuery += "DETACH DATABASE ";
        sqlQuery += attachedDb;
        m_db.executeUpdate(sqlQuery);
    }
    m_attachedDbList.clear();
}

} // namespace db_with_relocation
} // namespace sql_databases

/**
 * Automatically generated by Zserio C++ extension version 2.8.0.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, sourcesAmalgamation, stdAllocator.
 */

#include <zserio/SqliteException.h>

#include <sql_databases/db_with_relocation/AmericaDb.h>

namespace sql_databases
{
namespace db_with_relocation
{

AmericaDb::AmericaDb(const ::zserio::string<>& dbFileName, const TRelocationMap& tableToDbFileNameRelocationMap,
        const allocator_type& allocator) :
        ::zserio::AllocatorHolder<allocator_type>(allocator),
        m_tableToAttachedDbNameRelocationMap(allocator)
{
    sqlite3 *internalConnection = nullptr;
    const int sqliteOpenMode = SQLITE_OPEN_URI | SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE;
    const int result = sqlite3_open_v2(dbFileName.c_str(), &internalConnection, sqliteOpenMode, nullptr);
    m_db.reset(internalConnection, ::zserio::SqliteConnection::INTERNAL_CONNECTION);
    if (result != SQLITE_OK)
    {
        throw ::zserio::SqliteException("AmericaDb::open(): can't open DB ") << dbFileName.c_str() << ": " <<
                ::zserio::SqliteErrorCode(result);
    }

    ::std::map<::zserio::StringView, ::zserio::string<>> dbFileNameToAttachedDbNameMap(
            get_allocator_ref());
    for (const auto& relocation : tableToDbFileNameRelocationMap)
    {
        const ::zserio::string<>& tableName = relocation.first;
        const ::zserio::string<>& fileName = relocation.second;
        auto attachedDbIt = dbFileNameToAttachedDbNameMap.find(fileName);
        if (attachedDbIt == dbFileNameToAttachedDbNameMap.end())
        {
            ::zserio::string<> attachedDbName =
                    ::zserio::stringViewToString(databaseName(), get_allocator_ref()) + "_" + tableName;
            attachDatabase(fileName, attachedDbName);
            attachedDbIt = dbFileNameToAttachedDbNameMap.emplace(fileName, ::std::move(attachedDbName)).first;
        }
        m_tableToAttachedDbNameRelocationMap.emplace(
                ::zserio::string<>(tableName, get_allocator_ref()),
                ::zserio::string<>(attachedDbIt->second, get_allocator_ref()));
    }

    initTables();
}

AmericaDb::AmericaDb(const ::zserio::string<>& fileName, const allocator_type& allocator) :
        AmericaDb(fileName, TRelocationMap(allocator), allocator)
{}

AmericaDb::AmericaDb(sqlite3* externalConnection, const TRelocationMap& tableToAttachedDbNameRelocationMap,
        const allocator_type& allocator) :
        ::zserio::AllocatorHolder<allocator_type>(allocator),
        m_tableToAttachedDbNameRelocationMap(tableToAttachedDbNameRelocationMap, allocator)
{
    m_db.reset(externalConnection, ::zserio::SqliteConnection::EXTERNAL_CONNECTION);
    initTables();
}

AmericaDb::AmericaDb(sqlite3* externalConnection, const allocator_type& allocator) :
        AmericaDb(externalConnection, TRelocationMap(allocator), allocator)
{}

AmericaDb::~AmericaDb()
{
    detachDatabases();
}

::zserio::SqliteConnection& AmericaDb::connection() noexcept
{
    return m_db;
}

::sql_databases::db_with_relocation::CountryMapTable& AmericaDb::getUsa() noexcept
{
    return *m_usa_;
}

::sql_databases::db_with_relocation::CountryMapTable& AmericaDb::getCanada() noexcept
{
    return *m_canada_;
}

::sql_databases::db_with_relocation::CountryMapTable& AmericaDb::getSlovakia() noexcept
{
    return *m_slovakia_;
}

::sql_databases::db_with_relocation::CountryMapTable& AmericaDb::getCzechia() noexcept
{
    return *m_czechia_;
}

void AmericaDb::createSchema()
{
    const bool wasTransactionStarted = m_db.startTransaction();

    m_usa_->createTable();
    m_canada_->createTable();
    m_slovakia_->createTable();
    m_czechia_->createTable();

    m_db.endTransaction(wasTransactionStarted);
}

void AmericaDb::createSchema(const ::std::set<::zserio::string<>>&)
{
    createSchema();
}

void AmericaDb::deleteSchema()
{
    const bool wasTransactionStarted = m_db.startTransaction();

    m_usa_->deleteTable();
    m_canada_->deleteTable();
    m_slovakia_->deleteTable();
    m_czechia_->deleteTable();

    m_db.endTransaction(wasTransactionStarted);
}

::zserio::StringView AmericaDb::databaseName() noexcept
{
    return ::zserio::makeStringView("AmericaDb");
}

::zserio::StringView AmericaDb::tableNameUsa() noexcept
{
    return ::zserio::makeStringView("usa");
}

::zserio::StringView AmericaDb::tableNameCanada() noexcept
{
    return ::zserio::makeStringView("canada");
}

::zserio::StringView AmericaDb::tableNameSlovakia() noexcept
{
    return ::zserio::makeStringView("slovakia");
}

::zserio::StringView AmericaDb::tableNameCzechia() noexcept
{
    return ::zserio::makeStringView("czechia");
}

const ::std::array<::zserio::StringView, 4>& AmericaDb::tableNames() noexcept
{
    static const ::std::array<::zserio::StringView, 4> names =
    {
        tableNameUsa(),
        tableNameCanada(),
        tableNameSlovakia(),
        tableNameCzechia()
    };

    return names;
}

void AmericaDb::initTables()
{
    static ::zserio::StringView EMPTY_STR = ::zserio::StringView();
    auto relocationIt = m_tableToAttachedDbNameRelocationMap.find(
            ::zserio::stringViewToString(tableNameUsa(), get_allocator_ref()));
    m_usa_ = ::zserio::allocate_unique<::sql_databases::db_with_relocation::CountryMapTable>(
            get_allocator_ref(), this->m_db, tableNameUsa(),
            relocationIt != m_tableToAttachedDbNameRelocationMap.end() ? relocationIt->second : EMPTY_STR,
            get_allocator_ref());

    relocationIt = m_tableToAttachedDbNameRelocationMap.find(
            ::zserio::stringViewToString(tableNameCanada(), get_allocator_ref()));
    m_canada_ = ::zserio::allocate_unique<::sql_databases::db_with_relocation::CountryMapTable>(
            get_allocator_ref(), this->m_db, tableNameCanada(),
            relocationIt != m_tableToAttachedDbNameRelocationMap.end() ? relocationIt->second : EMPTY_STR,
            get_allocator_ref());

    relocationIt = m_tableToAttachedDbNameRelocationMap.find(
            ::zserio::stringViewToString(tableNameSlovakia(), get_allocator_ref()));
    m_slovakia_ = ::zserio::allocate_unique<::sql_databases::db_with_relocation::CountryMapTable>(
            get_allocator_ref(), this->m_db, tableNameSlovakia(),
            relocationIt != m_tableToAttachedDbNameRelocationMap.end() ? relocationIt->second : EMPTY_STR,
            get_allocator_ref());

    relocationIt = m_tableToAttachedDbNameRelocationMap.find(
            ::zserio::stringViewToString(tableNameCzechia(), get_allocator_ref()));
    m_czechia_ = ::zserio::allocate_unique<::sql_databases::db_with_relocation::CountryMapTable>(
            get_allocator_ref(), this->m_db, tableNameCzechia(),
            relocationIt != m_tableToAttachedDbNameRelocationMap.end() ? relocationIt->second : EMPTY_STR,
            get_allocator_ref());
}

void AmericaDb::attachDatabase(::zserio::StringView fileName, ::zserio::StringView attachedDbName)
{
    ::zserio::string<> sqlQuery(get_allocator_ref());
    sqlQuery += "ATTACH DATABASE '";
    sqlQuery += fileName;
    sqlQuery += "' AS ";
    sqlQuery += attachedDbName;

    m_db.executeUpdate(sqlQuery);

    m_attachedDbList.push_back(::zserio::stringViewToString(attachedDbName, get_allocator_ref()));
}

void AmericaDb::detachDatabases()
{
    for (const auto& attachedDb : m_attachedDbList)
    {
        ::zserio::string<> sqlQuery(get_allocator_ref());
        sqlQuery += "DETACH DATABASE ";
        sqlQuery += attachedDb;
        m_db.executeUpdate(sqlQuery);
    }
    m_attachedDbList.clear();
}

} // namespace db_with_relocation
} // namespace sql_databases

/**
 * Automatically generated by Zserio C++ extension version 2.8.0.
 * Generator setup: writerCode, pubsubCode, serviceCode, sqlCode, sourcesAmalgamation, stdAllocator.
 */

#include <zserio/CppRuntimeException.h>
#include <zserio/SqliteException.h>
#include <zserio/BitStreamReader.h>
#include <algorithm>
#include <zserio/BitFieldUtil.h>
#include <zserio/BitStreamWriter.h>
#include <zserio/ArrayTraits.h>
#include <zserio/BitBuffer.h>
#include <zserio/StringView.h>

#include <sql_databases/db_with_relocation/CountryMapTable.h>

namespace sql_databases
{
namespace db_with_relocation
{

CountryMapTable::CountryMapTable(::zserio::SqliteConnection& db, ::zserio::StringView tableName,
        ::zserio::StringView attachedDbName, const allocator_type& allocator) :
        ::zserio::AllocatorHolder<allocator_type>(allocator),
        m_db(db), m_name(tableName), m_attachedDbName(attachedDbName)
{
}

CountryMapTable::CountryMapTable(::zserio::SqliteConnection& db, ::zserio::StringView tableName,
        const allocator_type& allocator) :
        CountryMapTable(db, tableName, ::zserio::StringView(), allocator)
{
}

void CountryMapTable::createTable()
{
    ::zserio::string<> sqlQuery(get_allocator_ref());
    appendCreateTableToQuery(sqlQuery);
    m_db.executeUpdate(sqlQuery);
}

void CountryMapTable::deleteTable()
{
    ::zserio::string<> sqlQuery(get_allocator_ref());
    sqlQuery += "DROP TABLE ";
    appendTableNameToQuery(sqlQuery);
    m_db.executeUpdate(sqlQuery);
}

CountryMapTable::Reader CountryMapTable::createReader(::zserio::StringView condition) const
{
    ::zserio::string<> sqlQuery(get_allocator_ref());
    sqlQuery +=
            "SELECT "
            "tileId, "
            "tile"
            " FROM ";
    appendTableNameToQuery(sqlQuery);
    if (!condition.empty())
    {
        sqlQuery += " WHERE ";
        sqlQuery += condition;
    }

    return Reader(m_db, sqlQuery, get_allocator_ref());
}

CountryMapTable::Reader::Reader(::zserio::SqliteConnection& db, const ::zserio::string<>& sqlQuery, const allocator_type& allocator) :
        ::zserio::AllocatorHolder<allocator_type>(allocator),
        m_stmt(db.prepareStatement(sqlQuery))
{
    makeStep();
}

bool CountryMapTable::Reader::hasNext() const noexcept
{
    return m_lastResult == SQLITE_ROW;
}

CountryMapTable::Row CountryMapTable::Reader::next()
{
    if (!hasNext())
    {
        throw ::zserio::SqliteException("Table::Reader::next: next row is not available: ") <<
                ::zserio::SqliteErrorCode(m_lastResult);
    }

    Row row;

    // field tileId
    if (sqlite3_column_type(m_stmt.get(), 0) != SQLITE_NULL)
    {
        const int64_t intValue = sqlite3_column_int64(m_stmt.get(), 0);
        row.setTileId(static_cast<int32_t>(intValue));
    }

    // field tile
    if (sqlite3_column_type(m_stmt.get(), 1) != SQLITE_NULL)
    {
        const void* blobData = sqlite3_column_blob(m_stmt.get(), 1);
        const int blobDataLength = sqlite3_column_bytes(m_stmt.get(), 1);
        ::zserio::BitStreamReader reader(reinterpret_cast<const uint8_t*>(blobData),
                static_cast<size_t>(blobDataLength));
        ::sql_databases::db_with_relocation::Tile blob(reader, get_allocator_ref());
        row.setTile(::std::move(blob));
    }

    makeStep();

    return row;
}

void CountryMapTable::Reader::makeStep()
{
    m_lastResult = sqlite3_step(m_stmt.get());
    if (m_lastResult != SQLITE_ROW && m_lastResult != SQLITE_DONE)
    {
        throw ::zserio::SqliteException("CountryMapTable::Read: sqlite3_step() failed: ") <<
                ::zserio::SqliteErrorCode(m_lastResult);
    }
}

void CountryMapTable::write(::zserio::Span<Row> rows)
{
    // assemble sql query
    ::zserio::string<> sqlQuery(get_allocator_ref());
    sqlQuery += "INSERT INTO ";
    appendTableNameToQuery(sqlQuery);
    sqlQuery +=
            "("
            "tileId, "
            "tile"
            ") VALUES (?, ?);";

    // write rows
    const bool wasTransactionStarted = m_db.startTransaction();
    ::std::unique_ptr<sqlite3_stmt, ::zserio::SqliteFinalizer> statement(m_db.prepareStatement(sqlQuery));

    for (Row& row : rows)
    {
        writeRow(row, *statement);
        int result = sqlite3_step(statement.get());
        if (result != SQLITE_DONE)
        {
            throw ::zserio::SqliteException("Write: sqlite3_step() failed: ") <<
                    ::zserio::SqliteErrorCode(result);
        }

        sqlite3_clear_bindings(statement.get());
        result = sqlite3_reset(statement.get());
        if (result != SQLITE_OK)
        {
            throw ::zserio::SqliteException("Write: sqlite3_reset() failed: ") <<
                    ::zserio::SqliteErrorCode(result);
        }
    }

    m_db.endTransaction(wasTransactionStarted);
}

void CountryMapTable::update(Row& row, ::zserio::StringView whereCondition)
{
    // assemble sql query
    ::zserio::string<> sqlQuery(get_allocator_ref());
    sqlQuery += "UPDATE ";
    appendTableNameToQuery(sqlQuery);
    sqlQuery +=
            " SET"
            " tileId=?,"
            " tile=?"
            " WHERE ";
    sqlQuery += whereCondition;

    // update row
    ::std::unique_ptr<sqlite3_stmt, ::zserio::SqliteFinalizer> statement(m_db.prepareStatement(sqlQuery));
    writeRow(row, *statement);
    const int result = sqlite3_step(statement.get());
    if (result != SQLITE_DONE)
        throw ::zserio::SqliteException("Update: sqlite3_step() failed: ") << ::zserio::SqliteErrorCode(result);
}

void CountryMapTable::writeRow(Row& row, sqlite3_stmt& statement)
{
    row.initializeOffsets();

    int result;

    // field tileId
    if (!row.isTileIdSet())
    {
        result = sqlite3_bind_null(&statement, 1);
    }
    else
    {
        const int64_t intValue = static_cast<int64_t>(row.getTileId());
        result = sqlite3_bind_int64(&statement, 1, intValue);
    }
    if (result != SQLITE_OK)
    {
        throw ::zserio::SqliteException("CountryMapTable::WriteRow: sqlite3_bind() for field tileId failed: ") <<
                ::zserio::SqliteErrorCode(result);
    }

    // field tile
    if (!row.isTileSet())
    {
        result = sqlite3_bind_null(&statement, 2);
    }
    else
    {
        const ::sql_databases::db_with_relocation::Tile& blob = row.getTile();
        ::zserio::BitBuffer bitBuffer(blob.bitSizeOf(), get_allocator_ref());
        ::zserio::BitStreamWriter writer(bitBuffer);
        blob.write(writer);
        result = sqlite3_bind_blob(&statement, 2, bitBuffer.getBuffer(),
                static_cast<int>(bitBuffer.getByteSize()), SQLITE_TRANSIENT);
    }
    if (result != SQLITE_OK)
    {
        throw ::zserio::SqliteException("CountryMapTable::WriteRow: sqlite3_bind() for field tile failed: ") <<
                ::zserio::SqliteErrorCode(result);
    }
}

void CountryMapTable::appendCreateTableToQuery(::zserio::string<>& sqlQuery) const
{
    sqlQuery += "CREATE TABLE ";
    appendTableNameToQuery(sqlQuery);
    sqlQuery += '(';
    sqlQuery += "tileId INTEGER";
    sqlQuery += ' ';
    sqlQuery += ::zserio::makeStringView("PRIMARY KEY DEFAULT 0 NOT NULL");
    sqlQuery += ", tile BLOB";
    sqlQuery += ", ";
    sqlQuery += ::zserio::makeStringView("check tileId = 0");
    sqlQuery += ')';
}

void CountryMapTable::appendTableNameToQuery(::zserio::string<>& sqlQuery) const
{
    if (!m_attachedDbName.empty())
    {
        sqlQuery += m_attachedDbName;
        sqlQuery += '.';
    }
    sqlQuery += m_name;
}

int32_t CountryMapTable::Row::getTileId() const
{
    return m_tileId_.value();
}

void CountryMapTable::Row::setTileId(int32_t tileId_)
{
    m_tileId_ = tileId_;
}

void CountryMapTable::Row::resetTileId()
{
    m_tileId_.reset();
}

bool CountryMapTable::Row::isTileIdSet() const
{
    return m_tileId_.hasValue();
}

::sql_databases::db_with_relocation::Tile& CountryMapTable::Row::getTile()
{
    return m_tile_.value();
}

const ::sql_databases::db_with_relocation::Tile& CountryMapTable::Row::getTile() const
{
    return m_tile_.value();
}

void CountryMapTable::Row::setTile(const ::sql_databases::db_with_relocation::Tile& tile_)
{
    m_tile_ = tile_;
}

void CountryMapTable::Row::setTile(::sql_databases::db_with_relocation::Tile&& tile_)
{
    m_tile_ = ::std::move(tile_);
}

void CountryMapTable::Row::resetTile()
{
    m_tile_.reset();
}

bool CountryMapTable::Row::isTileSet() const
{
    return m_tile_.hasValue();
}

void CountryMapTable::Row::initializeOffsets()
{
    if (m_tile_)
        m_tile_->initializeOffsets();
}

} // namespace db_with_relocation
} // namespace sql_databases