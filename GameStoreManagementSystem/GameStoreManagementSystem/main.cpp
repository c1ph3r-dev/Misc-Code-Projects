#include <stdlib.h>
#include <iostream>

#include "csv.h"
#include "data.h"

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
using namespace std;

void Initialize(sql::Connection* con)
{
	sql::Statement* stmt;

	stmt = con->createStatement();
	stmt->execute(
		"CREATE TABLE IF NOT EXISTS inventory (product_id INT NOT NULL AUTO_INCREMENT, product_name VARCHAR(50) NOT NULL, cost DOUBLE(6, 2) NOT NULL, selling_price DOUBLE(6, 2) NOT NULL, quantity INT NOT NULL, PRIMARY KEY (product_id));"
	);

	stmt->execute(
		"CREATE TABLE IF NOT EXISTS transactions (transaction_id INT NOT NULL, product_sold INT, quantity_sold INT NOT NULL, date_of_transaction VARCHAR(10) NOT NULL, PRIMARY KEY (transaction_id, product_sold), FOREIGN KEY(product_sold) REFERENCES inventory(product_id) ON DELETE CASCADE);"
	);

	stmt->execute(
		"CREATE TABLE IF NOT EXISTS daily_sales (sales_date VARCHAR(10) NOT NULL, total_sold DEC(10, 2) NOT NULL, PRIMARY KEY (sales_date));"
	);
	delete stmt;
}

void AddProduct(sql::Connection* con)
{
	system("cls");

	std::vector<Product> products;

	while (true)
	{
		std::string TempString;
		Product product;
		std::cout << "Please enter the name of the product: ";
		std::cin >> product.ProductName;
		std::cout << "Please enter the cost price of the product: ";
		std::cin >> TempString;
		product.Cost = stof(TempString);
		std::cout << "Please enter the selling price of the product: ";
		std::cin >> TempString;
		product.SellingPrice = stof(TempString);

		std::cout << "Is there any quantity in stock currently? (y/n) ";
		std::cin >> TempString;

		if (TempString == "n")
			product.Quantity = 0;
		else
		{
			std::cout << "Enter current amount in stock: ";
			std::cin >> TempString;
			product.Quantity = stoi(TempString);
		}

		products.push_back(product);

		std::cout << "Would you like to add another product? (y/n) ";
		std::cin >> TempString;

		if (TempString != "y")
			break;

		system("cls");
	}

	sql::PreparedStatement* pstmt;

	pstmt = con->prepareStatement("INSERT INTO inventory(product_name, cost, selling_price, quantity) VALUES(?,?,?,?)");

	for (size_t i = 0; i < products.size(); i++)
	{
		pstmt->setString(1, products[i].ProductName.c_str());
		pstmt->setDouble(2, products[i].Cost);
		pstmt->setDouble(3, products[i].SellingPrice);
		pstmt->setInt(4, products[i].Quantity);
		pstmt->execute();
	}

	delete pstmt;
}

int main()
{
	const string server = "tcp://127.0.0.1:3306";
	const string username = "root";
	string* password = new string;

	sql::Driver* driver;
	sql::Connection* con;

	std::cout << "Enter password for root: ";
	std::cin >> *password;

	try
	{
		driver = get_driver_instance();
		con = driver->connect(server, username, *password);
	}
	catch (sql::SQLException e)
	{
		cout << "Could not connect to server. Error message: " << e.what() << endl;
		delete password;
		system("pause");
		exit(1);
	}

	con->setSchema("store_cpp");
	system("cls");

	Initialize(con);

	std::cout << "Menu:\n"
		<< "1. Add New Product\n"
		<< "selection-> ";

	int option;
	std::cin >> option;

	switch (option)
	{
	case 1:
		AddProduct(con);
		break;
	default:
		break;
	}

	delete con;

	return 0;
}