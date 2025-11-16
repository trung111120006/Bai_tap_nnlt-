#include <bits/stdc++.h>
using namespace std;

struct Time {
    int day, month, year;
    int hour, minute, second;
};

struct Order {
    Time purchased;
    Time prepared;
    Time packaged;
    Time delivered;
    Time received;
};

long long convert(const Time& t) {
    return t.second + t.minute * 60 + t.hour * 3600 + 
           t.day * 86400 + t.month * 2592000 + t.year * 31104000;
}

long long time_purchased_prepared(const vector<Order>& orders) {
    long long total = 0;
    for (auto& o : orders)
        total += convert(o.prepared) - convert(o.purchased);
    return total;
}

long long time_purchased_packaged(const vector<Order>& orders) {
    long long total = 0;
    for (auto& o : orders)
        total += convert(o.packaged) - convert(o.purchased);
    return total;
}

long long time_packaged_delivered(const vector<Order>& orders) {
    long long total = 0;
    for (auto& o : orders)
        total += convert(o.delivered) - convert(o.packaged);
    return total;
}

long long time_delivered_received(const vector<Order>& orders) {
    long long total = 0;
    for (auto& o : orders)
        total += convert(o.received) - convert(o.delivered);
    return total;
}

int main() {
    cout << "The number of orders: ";
    int n;
    cin >> n;

    vector<Order> orders;

    for (int i = 0; i < n; i++) {
        Order ord;
        cout << "Order number " << i + 1 << ":\n";
        cin >> ord.purchased.day >> ord.purchased.month >> ord.purchased.year
            >> ord.purchased.hour >> ord.purchased.minute >> ord.purchased.second;

        cin >> ord.prepared.day >> ord.prepared.month >> ord.prepared.year
            >> ord.prepared.hour >> ord.prepared.minute >> ord.prepared.second;

        cin >> ord.packaged.day >> ord.packaged.month >> ord.packaged.year
            >> ord.packaged.hour >> ord.packaged.minute >> ord.packaged.second;

        cin >> ord.delivered.day >> ord.delivered.month >> ord.delivered.year
            >> ord.delivered.hour >> ord.delivered.minute >> ord.delivered.second;

        cin >> ord.received.day >> ord.received.month >> ord.received.year
            >> ord.received.hour >> ord.received.minute >> ord.received.second;

        orders.push_back(ord);
    }

    vector<long long> times;
    times.push_back(time_purchased_prepared(orders));
    times.push_back(time_purchased_packaged(orders));
    times.push_back(time_packaged_delivered(orders));
    times.push_back(time_delivered_received(orders));

    long long mx = *max_element(times.begin(), times.end());

    cout << "The longest time interval is: " << mx << " seconds.\n";
}
