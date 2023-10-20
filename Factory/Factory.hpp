// Made With Xer At 2023:10:20 18:10
// Ref Web https://www.cnblogs.com/qicosmos/p/5090159.html
/*  
*	Imp A Advacne Factory :
*		auto-registration,The open-closed principle is followed
*		Add new classes without modifying the source code
* 
* 
*/

/*
* 
*	Imp Principle:
*			Maintaining A Factory::Map In A Factory class, The new produce class will be registered in Factory::Map.
*		Genericization of Product Classes via Variable Template Metaprogramming,
* 
*	
* 
* 
* 
*/


#include <map>
#include <string>
#include <functional>
#include <memory>
#include "Animals.hpp"


class Factory
{

public:

	template<typename T>
	class register_t
	{
		register_t(const std::string& key)
		{
			Factory::Get().map_.emplace(key, [] {return new T(); });
		}

		template<typename... Args>
		register_t(const std::string& key, Args... args)
		{
			Factory::Get().map_.emplace(key, [&] {return new T(args...); });
		}

	};

	static Animals* produce(const std::string& key)
	{
		if (map_.find(key) == map_.end())

			throw std::invalid_argument("the message key is not exist!");
		return map_[key]();

	}

	static std::unique_ptr<Animals> Produce_unique(const std::string& key)
	{
		return std::unique_ptr<Animals>(produce(key));
	}

	static std::shared_ptr<Animals> produce_shared(const std::string& key)
	{
		return std::shared_ptr<Animals>(produce(key));
	}

private:

	Factory(){}
	Factory(const Factory&) = delete;
	Factory(Factory&&) = delete;

	static Factory& Get()
	{
		static Factory instance;
		return instance;
	}

	static std::map<std::string, std::function<Animals*()>> map_;

};

std::map<std::string, std::function<Animals*()>> Factory::map_;


#define REGISTER_MESSAGE_VNAME(T) reg_msg_##T##_
#define REGISTER_MESSAGE(T, key, ...) static Factory::register_t<T> REGISTER_MESSAGE_VNAME(T)(key, ##__VA_ARGS__);