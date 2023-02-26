# HTML page parser

## Version 0.0.1 (initial)

## Description
Current project will develop as a supporting library 
for parsing and storing specified information from HTML documents

### Phase 1
- Create initial interface of the main class
- Create initial logger manager for storing debug and error info
- Add basic class for defining common errors like an invalid file path or an empty document
- Add manager of reading HTML ducuments from different types (file, std::string, char array, etc.)

### Phase 2
- Add validation of THML document (check structure of a document)
- Create a supporting class for reading text info
- Create a supporting class for reading extern links info
- Create a supporting class for reading image links info
- Create a supporting class for reading other data types in documents 
  (need more deep investigation before starting implementation)
- Add storage for collected data (template DB in program memory or local template files)

### Phase 3
- Create error manager (full error definition, error handler, error manager)
- Add class for exporting data to specified file type
- Add supporting project as a submodule in other projects
- Finalize project architecture (code documentation, Updating README, freezing version)

# END