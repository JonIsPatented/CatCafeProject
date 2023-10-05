#ifndef JC_VISIT_LOG_H
#define JC_VISIT_LOG_H

#include "TimeHM.h"
#include "Customer.h"

namespace cc
{
	class Visit
	{
	public:
		Visit();
		Visit(const Visit&);
		Visit(Visit&&) noexcept;
		~Visit();
	public:
		Visit& operator=(const Visit&);
		Visit& operator=(Visit&&) noexcept;
	private:
		friend class Customer;
	private:
		Customer m_customer;
		TimeHM m_timeOfVisit;
	};
}

#endif
