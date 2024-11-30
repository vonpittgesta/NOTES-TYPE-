
#pragma once
#include <string>
#include <vector>
#include "Item.h"

enum class RequestStatus {
    Pending,
    Approved,
    Rejected
};

class Requests {
private:
    std::string requesterName;
    std::string requestDate;
    std::vector<Item> itemsRequested;
    RequestStatus status;

public:
    Requests(std::string requester, std::string date);

    void addItem(const Item& item);
    void approveRequest();
    void rejectRequest();
    bool isPending() const;
    void displayRequest() const;

    std::string getRequesterName() const;
    RequestStatus getStatus() const;
    std::vector<Item> getItemsRequested() const;
};
