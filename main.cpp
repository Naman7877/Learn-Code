#include <iostream>
#include <string>
#include "EmailCarbonFootprintCalculator.h"

using namespace std;

int main() {
    EmailCarbonFootprintCalculator calculatorFootPrints;
    string email;
    int inboxEmailCount;
    int spamEmailCount;
    int sendEmailCount;
    cout << "Enter the details related to email" << endl;
    cout << "Enter the Email: " << endl;
    cin >> email;
    cout << "Enter the inbox Email count: " << endl;
    cin >> inboxEmailCount;
    cout << "Enter the spam Email count: " << endl;
    cin >> spamEmailCount;
    cout << "Enter the sent Email count: " << endl;
    cin >> sendEmailCount;

    EmailCarbonFootprintCalculator::EmailStructure result = calculatorFootPrints.getCarbonFootprint(email, inboxEmailCount, spamEmailCount, sendEmailCount);
    std::cout << "Email ID: " << result.emailId << endl;
    std::cout << "Source: " << result.source << endl;
    std::cout << "Inbox: " << result.inbox << endl;
    std::cout << "Sent: " << result.sent << endl;
    std::cout << "Spam: " << result.spam << endl;
    return 0;
}
