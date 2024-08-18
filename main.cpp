#include <iostream>
using namespace std;

class Address {
  private:
    string name;
    string city;
    string fullAddress;
    
  public:
    Address(const string& name, const string& city, const string& fullAddress): 
      name(name), city(city), fullAddress(fullAddress) {}
    
}

class StandardPackage {
  private:
    Address senderAddress;
    Address receiverAddress;
    double weight;
    double price;
    
  public:
    StandardPackage(const Address& senderAddress, const Address& receiverAddress, const double& weight, const double& price): 
      senderAddress(senderAddress), receiverAddress(receiverAddress), weight(weight), price(price) {}
      
    double calculateTotalWeight() {
      return this->weight * this->price;
    }
    
    const Address& getSenderAddress() {
      return this->senderAddress;
    }
    void setSenderAddress(const Address& senderAddress) {
      this->senderAddress = senderAddress;
    }
    
    const Address& getReceiverAddress() {
      return this->receiverAddress;
    }
    void setReceiverAddress(const Address& receiverAddress) {
      this->receiverAddress = receiverAddress;
    }
    
    const double& getWeight() {
      return this->weight;
    }
    void setWeight(const double& weight) {
      return this->weight;
    }
    
    const double& getPrice() {
      return this->price;
    }
    void setPrice(const double& price) {
      this->price = price;
    }
}

class TwoDayPackage: public StandardPackage {
  private:
    double fixedFee;
    
  public:
    TwoDayPackage(const Address& senderAddress, const Address& receiverAddress, const double& weight, const double& price, double fixedFee): 
      StandardPackage(senderAddress, receiverAddress, weight, price), fixedFee(fixedFee) {}
    
    double calculateTotalWeight() {
      return StandardPackage::calculateTotalWeight() + this->fixedFee;
    }
    
    const double& getFixedFee() {
      return this->fixedFee;
    }
    void setFixedFee(const double& fixedFee) {
      this->fixedFee = fixedFee;
    }
}

class HeavyPackage: public StandardPackage {
  private:
    const double limitWeight = 100;
    double extraPrice;
    
  public:
    HeavyPackage(const Address& senderAddress, const Address& receiverAddress, const double& weight, const double& price, double extraPrice): 
      StandardPackage(senderAddress, receiverAddress, weight, price), extraPrice(extraPrice)) {}
      
    double calculateTotalWeight() {
      double normalPrice = StandardPackage::calculateTotalWeight();
      
      if (this->getWeight() > this->limitWeight) {
        normalPrice += (this->getWeight() - limitWeight) * extraPrice;
      }
      
      return normalPrice;
    }
    
    const double& getExtraPrice() {
      return this->extraPrice;
    }
    void setExtraPrice(const double& extraPrice) {
      this->extraPrice = extraPrice;
    }
}

class PaymentCard {
  private:
    string cardNumber;
    string expiryDate;
}

class CreditCard: public PaymentCard {};
class DepitCard: public PaymentCard {};

class Shipment {
  private:
    vector<StandardPackage> standardPackages;
    vector<TwoDayPackage> twoDayPackages;
    vector<HeavyPackage> heavyPackages;
    
    CreditCard creditCard;
    DepitCard depitCard;
    bool isCreditCardUsed;
    
  public:
    void addStandardPackage(const StandardPackage& package) {
      this->standardPackages.push_back(package);
    }
    void addTwoDayPackage(const TwoDayPackage& package) {
      this->twoDayPackages.push_back(package);
    }
    void addHeavyPackage(const HeavyPackage& package) {
      this->heavyPackages.push_back(package);
    }
    
    const CreditCard& getCreditCard() {
      return this->creditCard;
    }
    void setCreditCard(const CreditCard& creditCard) {
      this->creditCard = creditCard;
      this->isCreditCardUsed = true;
    }
    
    const DepitCard& getDepitCard() {
      return this->depitCard;
    }
    void setDepitCard(const DepitCard& depitCard) {
      this->depitCard = depitCard;
      this->isCreditCardUsed = false;
    }
    
    const double& calculateTotalWeight() {
      double result = 0;
      
      for (const StandardPackage& package : this->standardPackages) {
        result += package.calculateTotalWeight();
      }
      
      for (const TwoDayPackage& package : this->twoDayPackages) {
        result += package.calculateTotalWeight();
      }
      
      for (const HeavyPackage& package : this->heavyPackages) {
        result += package.calculateTotalWeight();
      }
      
      return result;
    }
}

class Customer {
  private:
    vector<Shipment> shipments;
    vector<CreditCard> creditCards;
    vector<DepitCard> depitCards;
    
    void addShipment() {}
}

int main() 
{
    cout << "Hello, World!";
    return 0;
}
