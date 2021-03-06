#ifndef SOCSIM_IMPORTER_H
#define SOCSIM_IMPORTER_H

#include <string>
#include "rapidjson/document.h"
#include "Society.h"

/**
 * A collection of static methods responsible for taking JSON data from ./res/ and importing into an existing or new
 * society. rapidjson is used to parse the files.
 */
class Importer {
public:
    // Various constants follow that store filenames and directories. Defined in implementation file.
    static const std::string res_directory;
    static const std::string message_types_filename;
    static const std::string people_filename;
    static const std::string relationship_types_filename;
    static const std::string relationships_filename;

    /**
     * Parses a file into rapidjson DOM Document
     * Pre-conditions:
     *  * filename is a path to an existing JSON file with an array as the root node; see `./res/*.json` for format
     * @param filename the path to the file
     * @return the rapidjson DOM Document representation of the JSON data in the file
     */
    static rapidjson::Document* parseFile(const std::string& filename);

    /**
     * Parses data in JSON files in ./res/ and imports them into the specified society
     * Pre-conditions:
     *  * specified society is non-null
     *  * specified society does not currently contain the data that's being imported (collisions will raise exceptions)
     * @param society the society to import into
     * @return the society that data was imported into
     */
    static Society* importTo(Society* society);
    /**
     * An alias to Importer::importTo that creates a new Society instead of using an existing one
     * Post-conditions:
     *  * Memory management of new Society is responsibility of caller
     * @return the new society with all the imported data
     */
    static Society* generate();
};


#endif //SOCSIM_IMPORTER_H
