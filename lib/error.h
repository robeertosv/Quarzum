string errors[] = {
    "File not found",
    "Format not supported"};

void throwError(int code)
{
    cerr << "[ ERROR ] - " << errors[code] << " - Error code: " << code << endl;
    exit(EXIT_FAILURE);
}