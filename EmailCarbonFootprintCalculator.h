#pragma once
#include <string>

class EmailCarbonFootprintCalculator {
private:
    double CARBON_FOOTPRINT_INBOX_EMAIL = 4.0;
    double CARBON_FOOTPRINT_SENT_EMAIL = 2.0;
    double CARBON_FOOTPRINT_SPAM_EMAIL = 0.3;

    double getInboxEmailsCarbonFootprint(int inboxEmails);
    double getSentEmailsCarbonFootprint(int sentEmails);
    double getSpamEmailsCarbonFootprint(int spamEmails);

public:
    struct EmailStructure {
        std::string emailId;
        std::string source;
        std::string inbox;
        std::string sent;
        std::string spam;
    };

    EmailStructure getCarbonFootprint(std::string& emailId, int inboxEmails, int sentEmails, int spamEmails);
    std::string getSource(std::string& emailId);
};
