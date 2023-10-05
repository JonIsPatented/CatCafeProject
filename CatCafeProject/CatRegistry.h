#ifndef JC_CAT_REGISTRY_H
#define JC_CAT_REGISTRY_H

#include <vector>

#include "Cat.h"

namespace cc
{
	class CatRegistry
	{
	public:
		void DisplayAllCats() const;
		void PromptCreate();
		void Add(const Cat&);
		void Add(Cat&&) noexcept;
		void Remove(const size_t);
	public:
		Cat& operator[](size_t);
		const Cat& operator[](size_t) const;
	public:
		CatRegistry();
		CatRegistry(const CatRegistry&);
		CatRegistry(CatRegistry&&) noexcept;
		~CatRegistry();
	public:
		CatRegistry& operator=(const CatRegistry&);
		CatRegistry& operator=(CatRegistry&&) noexcept;
	private:
		std::vector<Cat> m_cats;
	};
}

#endif
