#include "EmailCarbonFootprintCalculator.h"

double EmailCarbonFootprintCalculator::getInboxEmailsCarbonFootprint(int inboxEmails) {
    return (inboxEmails * CARBON_FOOTPRINT_INBOX_EMAIL) / 1000.0;
}

double EmailCarbonFootprintCalculator::getSentEmailsCarbonFootprint(int sentEmails) {
    return (sentEmails * CARBON_FOOTPRINT_SENT_EMAIL) / 1000.0;
}

double EmailCarbonFootprintCalculator::getSpamEmailsCarbonFootprint(int spamEmails) {
    return (spamEmails * CARBON_FOOTPRINT_SPAM_EMAIL) / 1000.0;
}

EmailCarbonFootprintCalculator::EmailStructure EmailCarbonFootprintCalculator::getCarbonFootprint(std::string& emailId, int inboxEmails, int sentEmails, int spamEmails) {
    EmailStructure emailStructure;
    emailStructure.emailId = emailId;
    emailStructure.source = getSource(emailId);
    emailStructure.inbox = std::to_string(getInboxEmailsCarbonFootprint(inboxEmails)) + " KG";
    emailStructure.sent = std::to_string(getSentEmailsCarbonFootprint(sentEmails)) + " KG";
    emailStructure.spam = std::to_string(getSpamEmailsCarbonFootprint(spamEmails)) + " KG";

    return emailStructure;
}

std::string EmailCarbonFootprintCalculator::getSource(std::string& emailId) {
    if (emailId.find("gmail") != std::string::npos) {
        return "Gmail";
    } else if (emailId.find("outlook") != std::string::npos) {
        return "Outlook";
    } else if (emailId.find("yahoo") != std::string::npos) {
        return "Yahoo";
    }
    return "";
}
