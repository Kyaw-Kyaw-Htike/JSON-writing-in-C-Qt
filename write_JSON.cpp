/*
Assume the following json file is to be saved in the working directory with the file name "test_output.json":

    "Address": {
        "City": "London",
        "Country": "Great Britain",
        "Street": "Downing Street 10"
    },
    "Age": 43,
    "FirstName": "John",
    "LastName": "Doe",
    "Phone numbers": [
        "+44 1234567",
        "+44 2345678"
    ],
    "Some double numbers": [
        1.34,
        2.56
    ],
    "Some float numbers": [
        1,
        2.4000000953674316,
        3,
        4.999899864196777
    ],
    "Some integer numbers": [
        1,
        2,
        3,
        4,
        5,
        6
    ]
}
*/


using namespace std;

int main(int argc, char* args[])
{

	std::string firstname = "John";
	std::string lastname = "Doe";
	int age = 43;
	std::string street = "Downing Street 10";
	std::string city = "London";
	std::string country = "Great Britain";
	std::vector<std::string> phonenums({ "+44 1234567" , "+44 2345678" });
	std::vector<int>someIntegerNums({1,2,3,4,5,6});
	std::vector<float>someFloatNums({ 1,2.4f,3,4.9999f });
	std::vector<double>someDoubleNums({ 1.34,2.56});
	
	QFile file;
	file.setFileName("test_output.json");
	file.open(QIODevice::WriteOnly | QIODevice::Text);

	QJsonObject outer_dict;

	QString firstname_qstr = QString::fromStdString(firstname);
	QJsonValue firstname_val(firstname_qstr);
	outer_dict["FirstName"] = firstname_val;

	QString lastname_qstr = QString::fromStdString(lastname);
	QJsonValue lastname_val(lastname_qstr);
	outer_dict["LastName"] = lastname_val;

	QJsonValue age_val(age);
	outer_dict["Age"] = age_val;

	QString street_qstr = QString::fromStdString(street);
	QJsonValue street_val(street_qstr);
	QString city_qstr = QString::fromStdString(city);
	QJsonValue city_val(city_qstr);
	QString country_qstr = QString::fromStdString(country);
	QJsonValue country_val(country_qstr);
	QJsonObject address_dict;
	address_dict["Street"] = street_val;
	address_dict["City"] = city_val;
	address_dict["Country"] = country_val;
	outer_dict["Address"] = address_dict;

	QJsonArray phonenums_array;
	for (size_t i = 0; i < phonenums.size(); i++)
	{
		QString phonenum_qstr = QString::fromStdString(phonenums[i]);
		QJsonValue phonenum_val(phonenum_qstr);
		phonenums_array.append(phonenum_val);
	}
	outer_dict["Phone numbers"] = phonenums_array;

	QJsonArray int_numbers_array;
	for (size_t i = 0; i < someIntegerNums.size(); i++)
	{
		int_numbers_array.append(someIntegerNums[i]);
	}
	outer_dict["Some integer numbers"] = int_numbers_array;

	QJsonArray float_numbers_array;
	for (size_t i = 0; i < someFloatNums.size(); i++)
	{
		float_numbers_array.append(someFloatNums[i]);
	}
	outer_dict["Some float numbers"] = float_numbers_array;

	QJsonArray double_numbers_array;
	for (size_t i = 0; i < someDoubleNums.size(); i++)
	{
		double_numbers_array.append(someDoubleNums[i]);
	}
	outer_dict["Some double numbers"] = double_numbers_array;

	file.write(QJsonDocument(outer_dict).toJson(QJsonDocument::Indented));
	file.close();
	
}