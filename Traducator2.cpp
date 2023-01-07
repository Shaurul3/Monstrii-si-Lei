#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <curl/curl.h>

// Replace YOUR_API_KEY with your actual API key
const std::string API_KEY = "AIzaSyAmk2PpfI4K7CBnobYtDV7esOTDXoK4l7I";

// This function receives the API response as a string and parses it
// to extract the translated text.
std::string parseResponse(const std::string& response) {
  size_t begin = response.find("\"translatedText\": \"") + 18;
  size_t end = response.find("\"", begin);
  return response.substr(begin, end - begin);
}

// This function sends an HTTP request to the Google Translate API
// and returns the response as a string.
std::string translate(const std::string& text, const std::string& target) {
  CURL *curl = curl_easy_init();
  if (!curl) return "";

  // Set the URL and the query parameters
  std::string url = "https://translation.googleapis.com/language/translate/v2?";
  url += "q=" + curl_easy_escape(curl, text.c_str(), text.size());
  url += "&target=" + target;
  url += "&key=" + API_KEY;

  curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
  curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
  curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
  curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

  // Set up a buffer to store the response
  std::string response;
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,
                   [](char* data, size_t size, size_t nmemb, std::string* buffer) -> size_t {
                     buffer->append(data, size * nmemb);
                     return size * nmemb;
                   });
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

  // Send the request
  CURLcode res = curl_easy_perform(curl);

  curl_easy_cleanup(curl);

  // Return the response if the request was successful,
  // otherwise return an empty string.
  return (res == CURLE_OK) ? parseResponse(response) : "";
}

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " input_file.csv output_file.csv" << std::endl;
    return 1;
  }

  std::ifstream input(argv[1]);
  std::ofstream output(argv[2]);

  std::string line;
  std::getline(input, line)) {
    // Split the line into fields
    std::string field;
    std::istringstream lineStream(line);
    while (std::getline(lineStream, field, ',')) {
      // Translate the field and write it to the output file
      std::string translated = translate(field, "ro");
      output << translated << ',';
    }
    output << '\n';
  }

  return 0;
}
