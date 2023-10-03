int Request::parseMultipartBody(const std::string& boundary)
{
    std::istringstream requestStream(_header_before);
    std::string line;

    // Skip request headers and move to the request body
    while (std::getline(requestStream, line) && !line.empty()) {
        // You may handle other headers here if needed
    }

    // Start parsing the multipart body
    bool inPart = false;
    std::string currentPart;
    std::string partHeader;
    std::string partContent;

    while (std::getline(requestStream, line)) {
        if (line == ("--" + boundary)) {
            if (!inPart) {
                inPart = true;
            } else {
                // Process the current part
                processMultipartPart(partHeader, partContent);

                // Reset for the next part
                partHeader.clear();
                partContent.clear();
            }
        } else if (line == ("--" + boundary + "--")) {
            // End of multipart data
            break;
        } else if (inPart) {
            // Append data to the current part
            if (partContent.empty()) {
                partHeader = line;
            } else {
                partContent += "\n" + line;
            }
        }
    }

    // Process the last part
    if (!partHeader.empty() && !partContent.empty()) {
        processMultipartPart(partHeader, partContent);
    }

    return 1;
}

void Request::processMultipartPart(const std::string& header, const std::string& content)
{
    // Parse and handle each part as needed
    // Here, you can extract form fields and file data from 'header' and 'content'
    // You may need to implement your logic for handling form fields and file uploads
}
