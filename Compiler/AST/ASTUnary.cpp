//
//  ASTUnary.cpp
//  Emojicode
//
//  Created by Theo Weidmann on 04/08/2017.
//  Copyright © 2017 Theo Weidmann. All rights reserved.
//

#include "ASTUnary.hpp"
#include "Analysis/FunctionAnalyser.hpp"
#include "CompilerError.hpp"
#include "Types/TypeExpectation.hpp"

namespace EmojicodeCompiler {

Type ASTIsError::analyse(FunctionAnalyser *analyser, const TypeExpectation &expectation) {
    Type type = analyser->expect(TypeExpectation(false, false), &value_);
    if (type.type() != TypeType::Error) {
        throw CompilerError(position(), "🚥 can only be used with 🚨.");
    }
    return analyser->boolean();
}

Type ASTUnwrap::analyse(FunctionAnalyser *analyser, const TypeExpectation &expectation) {
    Type t = analyser->expect(TypeExpectation(false, false), &value_);

    if (t.optional()) {
        t.setOptional(false);
        return t;
    }
    if (t.type() == TypeType::Error) {
        error_ = true;
        return t.genericArguments()[1];
    }

    throw CompilerError(position(), "🍺 can only be used with optionals or 🚨.");
}

Type ASTMetaTypeFromInstance::analyse(FunctionAnalyser *analyser, const TypeExpectation &expectation) {
    Type originalType = analyser->expect(TypeExpectation(false, false, false), &value_);
    analyser->validateMetability(originalType, position());
    originalType.setMeta(true);
    return originalType;
}

}  // namespace EmojicodeCompiler
