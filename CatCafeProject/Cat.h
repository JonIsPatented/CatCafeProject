#ifndef JC_CAT_H
#define JC_CAT_H

#include <string>

namespace cc
{
	class Cat
	{
	public:
		void DisplayInformation();
	public:
		Cat(const Cat&);
		Cat(Cat&&) noexcept;
		~Cat();
		Cat& operator=(const Cat&);
		Cat& operator=(Cat&&) noexcept;
	private:
		std::string m_name;
		std::string m_color;
		std::string m_pattern;
		uint32_t m_id;
		enum class Sex
		{
			MALE,
			FEMALE
		} m_sex;
		struct DateDMY
		{
			uint16_t day;
			uint16_t month;
			uint16_t year;
		} m_birthDate;
	private:
		Cat();
	public:
		friend class CatBuilder;
	};

	class CatBuilder
	{
	public:
		CatBuilder& Name(const std::string&);
		CatBuilder& Color(const std::string&);
		CatBuilder& Pattern(const std::string&);
		CatBuilder& ID(const uint64_t);
		CatBuilder& Sex(const std::string&);
		CatBuilder& BirthDate(const uint8_t, const uint8_t, const uint16_t);
	public:
		Cat CopyBuild();
		void ExtractBuild(Cat&);
	private:
		Cat m_cat;
	};
}

#endif
