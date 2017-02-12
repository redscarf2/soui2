/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"

#if ENABLE(Condition1) || ENABLE(Condition2)

#include "JSTestSerializedScriptValueInterface.h"

#include "SerializedScriptValue.h"
#include "TestSerializedScriptValueInterface.h"
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSTestSerializedScriptValueInterface);

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif
#if ENABLE(DFG_JIT)
#define INTRINSIC(intrinsic) , intrinsic
#else
#define INTRINSIC(intrinsic)
#endif

static const HashTableValue JSTestSerializedScriptValueInterfaceTableValues[] =
{
    { "value", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestSerializedScriptValueInterfaceValue), (intptr_t)0 THUNK_GENERATOR(0) INTRINSIC(DFG::NoIntrinsic) },
    { "constructor", DontEnum | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestSerializedScriptValueInterfaceConstructor), (intptr_t)0 THUNK_GENERATOR(0) INTRINSIC(DFG::NoIntrinsic) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) INTRINSIC(DFG::NoIntrinsic) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSTestSerializedScriptValueInterfaceTable = { 4, 3, JSTestSerializedScriptValueInterfaceTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif
#if ENABLE(DFG_JIT)
#define INTRINSIC(intrinsic) , intrinsic
#else
#define INTRINSIC(intrinsic)
#endif

static const HashTableValue JSTestSerializedScriptValueInterfaceConstructorTableValues[] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR(0) INTRINSIC(DFG::NoIntrinsic) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSTestSerializedScriptValueInterfaceConstructorTable = { 1, 0, JSTestSerializedScriptValueInterfaceConstructorTableValues, 0 };
const ClassInfo JSTestSerializedScriptValueInterfaceConstructor::s_info = { "TestSerializedScriptValueInterfaceConstructor", &DOMConstructorObject::s_info, &JSTestSerializedScriptValueInterfaceConstructorTable, 0, CREATE_METHOD_TABLE(JSTestSerializedScriptValueInterfaceConstructor) };

JSTestSerializedScriptValueInterfaceConstructor::JSTestSerializedScriptValueInterfaceConstructor(Structure* structure, JSDOMGlobalObject* globalObject)
    : DOMConstructorObject(structure, globalObject)
{
}

void JSTestSerializedScriptValueInterfaceConstructor::finishCreation(ExecState* exec, JSDOMGlobalObject* globalObject)
{
    Base::finishCreation(exec->globalData());
    ASSERT(inherits(&s_info));
    putDirect(exec->globalData(), exec->propertyNames().prototype, JSTestSerializedScriptValueInterfacePrototype::self(exec, globalObject), DontDelete | ReadOnly);
}

bool JSTestSerializedScriptValueInterfaceConstructor::getOwnPropertySlotVirtual(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getOwnPropertySlot(this, exec, propertyName, slot);
}

bool JSTestSerializedScriptValueInterfaceConstructor::getOwnPropertySlot(JSCell* cell, ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSTestSerializedScriptValueInterfaceConstructor, JSDOMWrapper>(exec, &JSTestSerializedScriptValueInterfaceConstructorTable, static_cast<JSTestSerializedScriptValueInterfaceConstructor*>(cell), propertyName, slot);
}

bool JSTestSerializedScriptValueInterfaceConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSTestSerializedScriptValueInterfaceConstructor, JSDOMWrapper>(exec, &JSTestSerializedScriptValueInterfaceConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif
#if ENABLE(DFG_JIT)
#define INTRINSIC(intrinsic) , intrinsic
#else
#define INTRINSIC(intrinsic)
#endif

static const HashTableValue JSTestSerializedScriptValueInterfacePrototypeTableValues[] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR(0) INTRINSIC(DFG::NoIntrinsic) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSTestSerializedScriptValueInterfacePrototypeTable = { 1, 0, JSTestSerializedScriptValueInterfacePrototypeTableValues, 0 };
const ClassInfo JSTestSerializedScriptValueInterfacePrototype::s_info = { "TestSerializedScriptValueInterfacePrototype", &JSC::JSNonFinalObject::s_info, &JSTestSerializedScriptValueInterfacePrototypeTable, 0, CREATE_METHOD_TABLE(JSTestSerializedScriptValueInterfacePrototype) };

JSObject* JSTestSerializedScriptValueInterfacePrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSTestSerializedScriptValueInterface>(exec, globalObject);
}

const ClassInfo JSTestSerializedScriptValueInterface::s_info = { "TestSerializedScriptValueInterface", &JSDOMWrapper::s_info, &JSTestSerializedScriptValueInterfaceTable, 0 , CREATE_METHOD_TABLE(JSTestSerializedScriptValueInterface) };

JSTestSerializedScriptValueInterface::JSTestSerializedScriptValueInterface(Structure* structure, JSDOMGlobalObject* globalObject, PassRefPtr<TestSerializedScriptValueInterface> impl)
    : JSDOMWrapper(structure, globalObject)
    , m_impl(impl)
{
}

void JSTestSerializedScriptValueInterface::finishCreation(JSGlobalData& globalData)
{
    Base::finishCreation(globalData);
    ASSERT(inherits(&s_info));
}

JSObject* JSTestSerializedScriptValueInterface::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return JSTestSerializedScriptValueInterfacePrototype::create(exec->globalData(), globalObject, JSTestSerializedScriptValueInterfacePrototype::createStructure(globalObject->globalData(), globalObject, globalObject->objectPrototype()));
}

bool JSTestSerializedScriptValueInterface::getOwnPropertySlotVirtual(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getOwnPropertySlot(this, exec, propertyName, slot);
}

bool JSTestSerializedScriptValueInterface::getOwnPropertySlot(JSCell* cell, ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    JSTestSerializedScriptValueInterface* thisObject = static_cast<JSTestSerializedScriptValueInterface*>(cell);
    ASSERT_GC_OBJECT_INHERITS(thisObject, &s_info);
    return getStaticValueSlot<JSTestSerializedScriptValueInterface, Base>(exec, &JSTestSerializedScriptValueInterfaceTable, thisObject, propertyName, slot);
}

bool JSTestSerializedScriptValueInterface::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    ASSERT_GC_OBJECT_INHERITS(this, &s_info);
    return getStaticValueDescriptor<JSTestSerializedScriptValueInterface, Base>(exec, &JSTestSerializedScriptValueInterfaceTable, this, propertyName, descriptor);
}

JSValue jsTestSerializedScriptValueInterfaceValue(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSTestSerializedScriptValueInterface* castedThis = static_cast<JSTestSerializedScriptValueInterface*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    TestSerializedScriptValueInterface* imp = static_cast<TestSerializedScriptValueInterface*>(castedThis->impl());
    JSValue result = imp->value() ? imp->value()->deserialize(exec, castedThis->globalObject()) : jsNull();
    return result;
}


JSValue jsTestSerializedScriptValueInterfaceConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSTestSerializedScriptValueInterface* domObject = static_cast<JSTestSerializedScriptValueInterface*>(asObject(slotBase));
    return JSTestSerializedScriptValueInterface::getConstructor(exec, domObject->globalObject());
}

JSValue JSTestSerializedScriptValueInterface::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSTestSerializedScriptValueInterfaceConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

JSC::JSValue toJS(JSC::ExecState* exec, JSDOMGlobalObject* globalObject, TestSerializedScriptValueInterface* impl)
{
    return wrap<JSTestSerializedScriptValueInterface>(exec, globalObject, impl);
}

TestSerializedScriptValueInterface* toTestSerializedScriptValueInterface(JSC::JSValue value)
{
    return value.inherits(&JSTestSerializedScriptValueInterface::s_info) ? static_cast<JSTestSerializedScriptValueInterface*>(asObject(value))->impl() : 0;
}

}

#endif // ENABLE(Condition1) || ENABLE(Condition2)
