cmake_minimum_required(VERSION 2.6)

project(GameServer)

find_package(Boost QUIET REQUIRED COMPONENTS program_options)

#cmake -DMAKE_BUILD_TYPE=Debug|Release
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -Wall -g -DDEBUG -D_DEBUG")
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -Wall -O3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -g -DDEBUG -D_DEBUG")

set(CMAKE_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Debug)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

add_compile_definitions(_CLIBXX_USE_CX11_ABI=0)

if(UNIX AND NOT APPLE)
	set(LINUX true)
endif()

if(LINUX)
	include_directories(
		${CMAKE_CURRENT_SOURCE_DIR}
		${CMAKE_CURRENT_SOURCE_DIR}/../IDL
		${CMAKE_CURRENT_SOURCE_DIR}/../Gamnet	
		/usr/include
		/usr/include/mysql
		/usr/include/mysql56
	)
	link_directories(
		/usr/local/lib
		/usr/lib64/mysql
		/usr/lib64/mysql56
		/usr/lib/x86_64-linux-gnu
		${CMAKE_CURRENT_SOURCE_DIR}/../Gamnet/Debug	
		${CMAKE_CURRENT_SOURCE_DIR}/../Common/Debug	
	)
endif()

if(APPLE)
	include_directories(
		../IDL
		/usr/local/Cellar/boost/1.64.0_1/include
		/usr/local/Cellar/curl/7.55.1/include
		/usr/local/Cellar/mysql-connector-c/6.1.6/include
		/usr/local/Cellar/openssl/1.0.2l/include
		/usr/local/include/Gamnet
	)
	link_directories(
		/usr/local/lib
		/usr/local/Cellar/boost/1.64.0_1/lib
		/usr/local/Cellar/curl/7.55.1/lib
		/usr/local/Cellar/mysql-connector-c/6.1.6/lib
		/usr/local/Cellar/openssl/1.0.2l/lib
		${CMAKE_CURRENT_SOURCE_DIR}/../Common/Debug	
	)
endif()

link_libraries(
	Common
	Gamnet
	boost_filesystem
	boost_system
	curl
	crypto
	ssl
	mysqlclient
	dl
	pthread
)

set(EXCLUDE_PATHS 
	".settings" 
	"CMakeFiles" 
	"Debug" 
	"Gon_Lua"
)
file(GLOB_RECURSE SRC "*.cpp" "*.c") 
foreach(TMP_PATH ${SRC})
	foreach(EXCLUDE_PATH ${EXCLUDE_PATHS})
		string(FIND ${TMP_PATH} ${EXCLUDE_PATH} RESULT)
		if(NOT ${RESULT} EQUAL -1)
			list(REMOVE_ITEM SRC ${TMP_PATH}) 
		endif()
	endforeach(EXCLUDE_PATH)
endforeach(TMP_PATH)

add_executable((XXBuildTest.${PROJECT_NAME} ${SRC})

target_link_libraries(helloworld PUBLIC Boost::program_options)



