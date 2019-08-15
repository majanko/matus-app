#include <iostream>
#include <sstream>
#include <dlt.h>

DLT_DECLARE_CONTEXT(dlt_context);


const std::string& returnHelloWorldString() {
    static const std::string text("!!! AM demo Matus application !!!");
    return text;
}

int main() {
    std::stringstream first_strm;

    /* Print 'Application management demo app' with problematic static const string */
    std::cout << returnHelloWorldString() << std::endl;

    /* Register DLT App and Ctx and enable printing of DLT messages to local console */
    DLT_REGISTER_APP("MAT","AM demo Matus application");
    DLT_REGISTER_CONTEXT(dlt_context,"CTX","AM demo matus application context");
    DLT_ENABLE_LOCAL_PRINT();

    /* Print 'Hello World' to local console */
    first_word.print(std::cout);
    std::cout << std::endl;

    /* Generate 'Hello World' DLT message */
    first_word.print(first_strm);
    DLT_LOG(dlt_context,DLT_LOG_INFO,DLT_CSTRING(first_strm.str().c_str()),DLT_STRING("!"));

    /* Disable printing of DLT messages to local console and unregister DLT App and Ctx */
    DLT_DISABLE_LOCAL_PRINT();
    DLT_UNREGISTER_CONTEXT(dlt_context);
    DLT_UNREGISTER_APP();

    return 0;
}

