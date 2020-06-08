#include <boost/program_options.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
	try {
		printf("bosst version = %s\n", BOOST_LIB_VERSION);

		printf("\nboost::program_options::options_description desc(\"All Options\");\n");

		boost::program_options::options_description desc("All Options");
		desc.add_options()
			("config", boost::program_options::value<std::string>()->default_value("config.xml"), "config file path")
			("help", "product help message");
		boost::program_options::variables_map vm;
		boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
		boost::program_options::notify(vm);

		printf("\nsuccess\n\n\n");
	}
	catch (const boost::bad_lexical_cast& e)
	{
		return (int)10;
	}
	catch (const std::exception& e)
	{
		return (int)50;
	}
	catch (...)
	{
		return (int)100;
	}
    return 0;
}


