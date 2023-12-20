#ifndef CLASS_UTILS_H_
#define CLASS_UTILS_H_

#define MAKE_ACCESSORS(VariableType, VariableName) \
inline VariableType Get##VariableName() const { return VariableName; } \
inline void Set##VariableName(const VariableType& Value) { VariableName = Value; }


#endif // CLASS_UTILS_H_