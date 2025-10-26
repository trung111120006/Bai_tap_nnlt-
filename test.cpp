using System;

class BankAccount
{
    // Private: chỉ trong class này truy cập được
    private decimal balance;

    // Protected: class con (nếu kế thừa BankAccount) có thể dùng
    protected string AccountType;

    // Public: có thể truy cập từ bất kỳ đâu
    public string Owner { get; set; }

    // Constructor
    public BankAccount(string owner, string accountType, decimal initialBalance)
    {
        Owner = owner;
        AccountType = accountType;
        balance = initialBalance;
    }

    // Public method: cho phép nạp tiền
    public void Deposit(decimal amount)
    {
        if (amount > 0)
        {
            balance += amount;
            Console.WriteLine($"{Owner} nạp {amount}, số dư mới: {balance}");
        }
    }

    // Public method: cho phép rút tiền
    public void Withdraw(decimal amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            Console.WriteLine($"{Owner} rút {amount}, số dư mới: {balance}");
        }
        else
        {
            Console.WriteLine("Không thể rút, số dư không đủ!");
        }
    }

    // Public method: chỉ đọc số dư (balance vẫn private)
    public decimal GetBalance()
    {
        return balance;
    }
}

// Class con kế thừa BankAccount
class SavingsAccount : BankAccount
{
    public SavingsAccount(string owner, decimal initialBalance)
        : base(owner, "Tiết kiệm", initialBalance) { }

    public void ShowAccountType()
    {
        // Có thể truy cập AccountType vì nó là protected
        Console.WriteLine($"Loại tài khoản: {AccountType}");
    }
}

class Program
{
    static void Main()
    {
        BankAccount acc = new BankAccount("An", "Thanh toán", 1000);

        // Có thể gọi các hàm public
        acc.Deposit(500);
        acc.Withdraw(200);
        Console.WriteLine($"Số dư hiện tại: {acc.GetBalance()}");

        // Không thể gọi trực tiếp acc.balance (private) hoặc acc.AccountType (protected)
        // acc.balance = 9999;  // ❌ Lỗi
        // acc.AccountType = "VIP"; // ❌ Lỗi

        SavingsAccount saving = new SavingsAccount("Bình", 2000);
        saving.ShowAccountType(); // Có thể truy cập protected từ class con
    }
}
