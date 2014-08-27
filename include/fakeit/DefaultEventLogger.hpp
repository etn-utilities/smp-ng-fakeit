/*
 * Copyright (c) 2014 Eran Pe'er.
 *
 * This program is made available under the terms of the MIT License.
 *
 * Created on Mar 10, 2014
 */

#ifndef DefaultEventHandler_h__
#define DefaultEventHandler_h__

#include <iostream>
#include "fakeit/EventHandler.hpp"
#include "fakeit/DefaultErrorFormatter.hpp"
#include "fakeit/FakeitExceptions.hpp"

namespace fakeit {

	struct DefaultEventLogger : public fakeit::EventHandler {

		virtual void handle(const UnexpectedMethodCallEvent& e) override {
			out << formatter.format(e) << std::endl;
		}

		virtual void handle(const SequenceVerificationEvent& e) override {
			out << formatter.format(e) << std::endl;
		}

		virtual void handle(const NoMoreInvocationsVerificationEvent& e) override {
			out << formatter.format(e) << std::endl;
		}

		DefaultEventLogger() :
			out(std::cout) {
		}
	private:
		DefaultErrorFormatter formatter;
		std::ostream& out;
	};

}

#endif