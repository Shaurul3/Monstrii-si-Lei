#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

#include <curl/curl.h>
#include <nlohmann/json.hpp>

// Replace with your own API key
const std::string API_KEY = "AIzaSyAmk2PpfI4K7CBnobYtDV7esOTDXoK4l7I";

// Returns a vector of pairs, where each pair represents a row in the CSV
// file. The first element in the pair is a vector of strings representing
// the cells in the row, and the second element is a boolean indicating
// whether the row should be translated (true) or not (false).
std::vector<std::pair<std::vector<std::string>, bool>> read_csv(const std::string& filename) {
    std::vector<std::pair<std::vector<std::string>, bool>> rows;

    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> cells;
        std::string cell;
        bool should_translate = false;
        for (char c : line) {
            if (c == ',') {
                cells.push_back(cell);
                cell.clear();
            } else if (c == '"') {
                should_translate = !should_translate;
            } else {
                cell += c;
            }
        }
        cells.push_back(cell);
        rows.emplace_back(cells, should_translate);
    }

    return rows;
}

// Translates the given text from English to Romanian using the Google
// Translate API. Returns the translated text on success, or an empty
// string on failure.
std::string translate(const std::string& text) {
    std::string url = "https://translation.googleapis.com/language/translate/v2?key=" + API_KEY + "&source=en&target=ro&q=" + text;

    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Error: Failed to initialize cURL" << std::endl;
        return "";
    }

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, nullptr);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, nullptr);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        std::cerr << "Error: cURL request failed: " << curl_easy_strerror(res) << std::endl;
        return "";
    }

    long response_code;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
    if (response_code != 200) {
        std::cerr << "Error: Invalid response code: " << response_code << std::endl

