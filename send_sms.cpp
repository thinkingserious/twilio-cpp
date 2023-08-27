#include <iostream>
#include <curl/curl.h>

// Function to send an SMS message using the Twilio API
void send_sms(const std::string& account_sid,
              const std::string& auth_token,
              const std::string& from_number,
              const std::string& to_number,
              const std::string& message)
{
    CURL *curl;
    CURLcode res;

    // Initialize the curl library
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (curl)
    {
        // Construct the Twilio API URL
        std::string url = "https://api.twilio.com/2010-04-01/Accounts/" + account_sid + "/Messages.json";

        // Construct the POST fields for the SMS message
        std::string post_fields = "From=" + from_number + "&To=" + to_number + "&Body=" + message;

        // Set the curl options for the Twilio API request
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_fields.c_str());
        curl_easy_setopt(curl, CURLOPT_USERNAME, account_sid.c_str());
        curl_easy_setopt(curl, CURLOPT_PASSWORD, auth_token.c_str());

        // Enable verbose output for the request
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

        // Perform the Twilio API request
        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
        {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }

        // Clean up the curl resources
        curl_easy_cleanup(curl);
    }

    // Clean up the curl global resources
    curl_global_cleanup();
}

int main()
{
    // Retrieve the Twilio account information and recipient phone number from environment variables
    std::string account_sid = std::getenv("TWILIO_ACCOUNT_SID");
    std::string auth_token = std::getenv("TWILIO_AUTH_TOKEN");
    std::string from_number = std::getenv("TWILIO_PHONE_NUMBER");
    std::string to_number = std::getenv("RECIPIENT_PHONE_NUMBER");

    // Set the message to be sent
    std::string message = "Hello from Twilio!";

    // Call the send_sms function to send the SMS message
    send_sms(account_sid, auth_token, from_number, to_number, message);

    return 0;
}