#include "PurchaseRequest.h"
#include <iostream>

Requests::Requests(std::string requester, std::string date)
    : requesterName(requester), requestDate(date), status(RequestStatus::Pending) {}

void Requests::addItem(const Item& item) {
    itemsRequested.push_back(item);
}

void Requests::approveRequest() {
    status = RequestStatus::Approved;
}

void Requests::rejectRequest() {
    status = RequestStatus::Rejected;
}

bool Requests::isPending() const {
    return status == RequestStatus::Pending;
}

void Requests::displayRequest() const {
    std::cout << "Requester: " << requesterName << "\n";
    std::cout << "Request Date: " << requestDate << "\n";
    std::cout << "Items Requested: \n";

    for (const auto& item : itemsRequested) {
        std::cout << " - " << item.getName() << " (Qty: " << item.getStockQuantity() << ")\n";
    }

    std::cout << "Status: ";
    switch (status) {
    case RequestStatus::Pending:
        std::cout << "Pending";
        break;
    case RequestStatus::Approved:
        std::cout << "Approved";
        break;
    case RequestStatus::Rejected:
        std::cout << "Rejected";
        break;
    }
    std::cout << std::endl;
}

std::string Requests::getRequesterName() const {
    return requesterName;
}

RequestStatus Requests::getStatus() const {
    return status;
}

std::vector<Item> Requests::getItemsRequested() const {
    return itemsRequested;
}
