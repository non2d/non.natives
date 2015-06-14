#include <io.nondev.nonlua.Lua.h>

//@line:32

    #include <nonlua.h>
     JNIEXPORT jobject JNICALL Java_io_nondev_nonlua_Lua_jniOpen(JNIEnv* env, jclass clazz, jint stateId) {


//@line:36

        return nonlua_open(env, stateId);
    

}

JNIEXPORT void JNICALL Java_io_nondev_nonlua_Lua_jniClose(JNIEnv* env, jclass clazz, jobject cptr) {


//@line:40

        lua_State * L = nonlua_getstate(env, cptr);

        lua_close(L);
    

}

JNIEXPORT void JNICALL Java_io_nondev_nonlua_Lua_jniOpenJava(JNIEnv* env, jclass clazz, jobject cptr) {


//@line:46

        lua_State* L = nonlua_getstate(env, cptr);

        lua_pushcfunction(L, luaopen_java);
        lua_pushstring(L, LUA_JAVALIBNAME);
        lua_call(L, 1, 0);

        lua_pop(L, 2);
    

}

JNIEXPORT void JNICALL Java_io_nondev_nonlua_Lua_jniOpenSocket(JNIEnv* env, jclass clazz, jobject cptr) {


//@line:56

        lua_State * L = nonlua_getstate(env, cptr);

        nonluaopen_socket(L);
    

}

static inline jint wrapped_Java_io_nondev_nonlua_Lua_jniLoadBuffer
(JNIEnv* env, jclass clazz, jobject cptr, jbyteArray obj_buff, jlong bsize, jstring obj_name, char* name, char* buff) {

//@line:62

        lua_State * L = nonlua_getstate(env, cptr);

        return (jint) luaL_loadbuffer(L, buff, (int) bsize, name);
    
}

JNIEXPORT jint JNICALL Java_io_nondev_nonlua_Lua_jniLoadBuffer(JNIEnv* env, jclass clazz, jobject cptr, jbyteArray obj_buff, jlong bsize, jstring obj_name) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);
	char* buff = (char*)env->GetPrimitiveArrayCritical(obj_buff, 0);

	jint JNI_returnValue = wrapped_Java_io_nondev_nonlua_Lua_jniLoadBuffer(env, clazz, cptr, obj_buff, bsize, obj_name, name, buff);

	env->ReleasePrimitiveArrayCritical(obj_buff, buff, 0);
	env->ReleaseStringUTFChars(obj_name, name);

	return JNI_returnValue;
}

static inline jint wrapped_Java_io_nondev_nonlua_Lua_jniLoadString
(JNIEnv* env, jclass clazz, jobject cptr, jstring obj_str, char* str) {

//@line:68

        lua_State * L   = nonlua_getstate(env, cptr);

        return (jint) luaL_loadstring(L, str);
    
}

JNIEXPORT jint JNICALL Java_io_nondev_nonlua_Lua_jniLoadString(JNIEnv* env, jclass clazz, jobject cptr, jstring obj_str) {
	char* str = (char*)env->GetStringUTFChars(obj_str, 0);

	jint JNI_returnValue = wrapped_Java_io_nondev_nonlua_Lua_jniLoadString(env, clazz, cptr, obj_str, str);

	env->ReleaseStringUTFChars(obj_str, str);

	return JNI_returnValue;
}

static inline jint wrapped_Java_io_nondev_nonlua_Lua_jniRunBuffer
(JNIEnv* env, jclass clazz, jobject cptr, jbyteArray obj_buff, jlong bsize, jstring obj_name, char* name, char* buff) {

//@line:75

        lua_State * L = nonlua_getstate(env, cptr);
        
        int ret = luaL_loadbuffer(L, buff, (int) bsize, name);
        int secRet = lua_pcall(L, 0, LUA_MULTRET, 0);

        return (jint) (ret || secRet);
    
}

JNIEXPORT jint JNICALL Java_io_nondev_nonlua_Lua_jniRunBuffer(JNIEnv* env, jclass clazz, jobject cptr, jbyteArray obj_buff, jlong bsize, jstring obj_name) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);
	char* buff = (char*)env->GetPrimitiveArrayCritical(obj_buff, 0);

	jint JNI_returnValue = wrapped_Java_io_nondev_nonlua_Lua_jniRunBuffer(env, clazz, cptr, obj_buff, bsize, obj_name, name, buff);

	env->ReleasePrimitiveArrayCritical(obj_buff, buff, 0);
	env->ReleaseStringUTFChars(obj_name, name);

	return JNI_returnValue;
}

static inline jint wrapped_Java_io_nondev_nonlua_Lua_jniRunString
(JNIEnv* env, jclass clazz, jobject cptr, jstring obj_str, char* str) {

//@line:84

        lua_State * L = nonlua_getstate(env, cptr);

        return (jint) luaL_dostring(L, str);
    
}

JNIEXPORT jint JNICALL Java_io_nondev_nonlua_Lua_jniRunString(JNIEnv* env, jclass clazz, jobject cptr, jstring obj_str) {
	char* str = (char*)env->GetStringUTFChars(obj_str, 0);

	jint JNI_returnValue = wrapped_Java_io_nondev_nonlua_Lua_jniRunString(env, clazz, cptr, obj_str, str);

	env->ReleaseStringUTFChars(obj_str, str);

	return JNI_returnValue;
}

JNIEXPORT jobject JNICALL Java_io_nondev_nonlua_Lua_jniNewThread(JNIEnv* env, jclass clazz, jobject cptr) {


//@line:90

        lua_State * L = nonlua_getstate(env, cptr);
        lua_State * newThread = lua_newthread(L);
        
        jclass tempClass = env->FindClass("io/nondev/nonlua/CPtr");
        jobject obj = env->AllocObject(tempClass);

        if (obj)
        {
            env->SetLongField(obj, env->GetFieldID(tempClass, "peer", "J"), (jlong) newThread);
        }

        return obj;
    

}

JNIEXPORT void JNICALL Java_io_nondev_nonlua_Lua_jniPushNil(JNIEnv* env, jclass clazz, jobject cptr) {


//@line:105

        lua_State * L = nonlua_getstate(env, cptr);

        lua_pushnil(L);
    

}

JNIEXPORT void JNICALL Java_io_nondev_nonlua_Lua_jniPushNumber(JNIEnv* env, jclass clazz, jobject cptr, jdouble db) {


//@line:111

        lua_State * L = nonlua_getstate(env, cptr);

        lua_pushnumber(L, (lua_Number) db);
    

}

JNIEXPORT void JNICALL Java_io_nondev_nonlua_Lua_jniPushString(JNIEnv* env, jclass clazz, jobject cptr, jstring obj_str) {
	char* str = (char*)env->GetStringUTFChars(obj_str, 0);


//@line:117

        lua_State * L = nonlua_getstate(env, cptr);

        lua_pushstring(L, str);
    
	env->ReleaseStringUTFChars(obj_str, str);

}

JNIEXPORT void JNICALL Java_io_nondev_nonlua_Lua_jniPushBoolean(JNIEnv* env, jclass clazz, jobject cptr, jint val) {


//@line:123

        lua_State * L = nonlua_getstate(env, cptr);

        lua_pushboolean(L, (int) val);
    

}

JNIEXPORT void JNICALL Java_io_nondev_nonlua_Lua_jniPushFunction(JNIEnv* env, jclass clazz, jobject cptr, jobject func) {


//@line:129

        lua_State* L = nonlua_getstate(env, cptr);

        nonlua_pushfunction(L, func);
    

}

JNIEXPORT void JNICALL Java_io_nondev_nonlua_Lua_jniPushObject(JNIEnv* env, jclass clazz, jobject cptr, jobject obj) {


//@line:135

        lua_State * L = nonlua_getstate(env, cptr);

        nonlua_pushobject(L, obj);
    

}

JNIEXPORT void JNICALL Java_io_nondev_nonlua_Lua_jniPushArray(JNIEnv* env, jclass clazz, jobject cptr, jobject obj) {


//@line:141

        lua_State * L = nonlua_getstate(env, cptr);

        nonlua_pusharray(L, obj);
    

}

JNIEXPORT jint JNICALL Java_io_nondev_nonlua_Lua_jniIsNumber(JNIEnv* env, jclass clazz, jobject cptr, jint index) {


//@line:147

        lua_State * L = nonlua_getstate(env, cptr);

        return (jint) lua_isnumber(L, (int) index);
    

}

JNIEXPORT jint JNICALL Java_io_nondev_nonlua_Lua_jniIsBoolean(JNIEnv* env, jclass clazz, jobject cptr, jint index) {


//@line:153

        lua_State * L = nonlua_getstate(env, cptr);

        return (jint) lua_isboolean(L, (int) index);
    

}

JNIEXPORT jint JNICALL Java_io_nondev_nonlua_Lua_jniIsString(JNIEnv* env, jclass clazz, jobject cptr, jint index) {


//@line:159

        lua_State * L = nonlua_getstate(env, cptr);

        return (jint) lua_isstring(L, (int) index);
    

}

JNIEXPORT jint JNICALL Java_io_nondev_nonlua_Lua_jniIsFunction(JNIEnv* env, jclass clazz, jobject cptr, jint index) {


//@line:165

        lua_State * L = nonlua_getstate(env, cptr);

        int idx = (jint)index;

        return (jint)(
            lua_isfunction(L, idx) || 
            lua_iscfunction(L, idx) ||
            nonlua_isfunction(L, idx)
       );
    

}

JNIEXPORT jint JNICALL Java_io_nondev_nonlua_Lua_jniIsObject(JNIEnv* env, jclass clazz, jobject cptr, jint index) {


//@line:177

        lua_State * L = nonlua_getstate(env, cptr);
        
        return (jint) nonlua_isobject(L, index);
    

}

JNIEXPORT jint JNICALL Java_io_nondev_nonlua_Lua_jniIsTable(JNIEnv* env, jclass clazz, jobject cptr, jint index) {


//@line:183

        lua_State * L = nonlua_getstate(env, cptr);

        return (jint) lua_istable(L, (int) index);
    

}

JNIEXPORT jint JNICALL Java_io_nondev_nonlua_Lua_jniIsUserdata(JNIEnv* env, jclass clazz, jobject cptr, jint index) {


//@line:189

        lua_State * L = nonlua_getstate(env, cptr);

        return (jint) lua_isuserdata(L, (int) index);
    

}

JNIEXPORT jint JNICALL Java_io_nondev_nonlua_Lua_jniIsNil(JNIEnv* env, jclass clazz, jobject cptr, jint index) {


//@line:195

        lua_State * L = nonlua_getstate(env, cptr);

        return (jint) lua_isnil(L, (int) index);
    

}

JNIEXPORT jint JNICALL Java_io_nondev_nonlua_Lua_jniIsNone(JNIEnv* env, jclass clazz, jobject cptr, jint index) {


//@line:201

        lua_State * L = nonlua_getstate(env, cptr);

        return (jint) lua_isnone(L, (int) index);
    

}

JNIEXPORT jdouble JNICALL Java_io_nondev_nonlua_Lua_jniToNumber(JNIEnv* env, jclass clazz, jobject cptr, jint index) {


//@line:207

        lua_State * L = nonlua_getstate(env, cptr);

        return (jdouble) lua_tonumber(L, index);
    

}

JNIEXPORT jint JNICALL Java_io_nondev_nonlua_Lua_jniToBoolean(JNIEnv* env, jclass clazz, jobject cptr, jint index) {


//@line:213

        lua_State * L = nonlua_getstate(env, cptr);

        return (jint) lua_toboolean(L, index);
    

}

JNIEXPORT jstring JNICALL Java_io_nondev_nonlua_Lua_jniToString(JNIEnv* env, jclass clazz, jobject cptr, jint index) {


//@line:219

        lua_State * L = nonlua_getstate(env, cptr);

        return env->NewStringUTF(lua_tostring(L, index));
    

}

JNIEXPORT jobject JNICALL Java_io_nondev_nonlua_Lua_jniToObject(JNIEnv* env, jclass clazz, jobject cptr, jint index) {


//@line:225

        lua_State * L = nonlua_getstate(env, cptr);

        int idx = (int)index;

        if (!nonlua_isobject(L, idx)) {
            return NULL;
        }
        
        jobject * obj = (jobject *)lua_touserdata(L, idx);
        return *obj;
    

}

JNIEXPORT void JNICALL Java_io_nondev_nonlua_Lua_jniGetGlobal(JNIEnv* env, jclass clazz, jobject cptr, jstring obj_key) {
	char* key = (char*)env->GetStringUTFChars(obj_key, 0);


//@line:238

        lua_State * L = nonlua_getstate(env, cptr);

        lua_getglobal(L, key);
    
	env->ReleaseStringUTFChars(obj_key, key);

}

JNIEXPORT void JNICALL Java_io_nondev_nonlua_Lua_jniSetGlobal(JNIEnv* env, jclass clazz, jobject cptr, jstring obj_key) {
	char* key = (char*)env->GetStringUTFChars(obj_key, 0);


//@line:244

        lua_State * L = nonlua_getstate(env, cptr);

        lua_setglobal(L, key);
    
	env->ReleaseStringUTFChars(obj_key, key);

}

JNIEXPORT void JNICALL Java_io_nondev_nonlua_Lua_jniGet(JNIEnv* env, jclass clazz, jobject cptr, jint index, jstring obj_key) {
	char* key = (char*)env->GetStringUTFChars(obj_key, 0);


//@line:250

        lua_State * L = nonlua_getstate(env, cptr);

        lua_getfield(L, (int) index, key);
    
	env->ReleaseStringUTFChars(obj_key, key);

}

JNIEXPORT void JNICALL Java_io_nondev_nonlua_Lua_jniSet(JNIEnv* env, jclass clazz, jobject cptr, jint index, jstring obj_key) {
	char* key = (char*)env->GetStringUTFChars(obj_key, 0);


//@line:256

        lua_State * L = nonlua_getstate(env, cptr);

        lua_setfield(L, (int) index, key);
    
	env->ReleaseStringUTFChars(obj_key, key);

}

JNIEXPORT void JNICALL Java_io_nondev_nonlua_Lua_jniGetI(JNIEnv* env, jclass clazz, jobject cptr, jint index, jint key) {


//@line:262

        lua_State * L = nonlua_getstate(env, cptr);

        lua_rawgeti(L, (int) index, (int) key);
    

}

JNIEXPORT void JNICALL Java_io_nondev_nonlua_Lua_jniSetI(JNIEnv* env, jclass clazz, jobject cptr, jint index, jint key) {


//@line:268

        lua_State * L = nonlua_getstate(env, cptr);

        lua_rawseti(L, (int) index, (int) key);
    

}

JNIEXPORT jint JNICALL Java_io_nondev_nonlua_Lua_jniGetTop(JNIEnv* env, jclass clazz, jobject cptr) {


//@line:274

        lua_State * L = nonlua_getstate(env, cptr);

        return (jint) lua_gettop(L);
    

}

JNIEXPORT void JNICALL Java_io_nondev_nonlua_Lua_jniSetTop(JNIEnv* env, jclass clazz, jobject cptr, jint top) {


//@line:280

        lua_State * L = nonlua_getstate(env, cptr);

        lua_settop(L, (int) top);
    

}

JNIEXPORT void JNICALL Java_io_nondev_nonlua_Lua_jniPop(JNIEnv* env, jclass clazz, jobject cptr, jint num) {


//@line:286

        lua_State * L = nonlua_getstate(env, cptr);

        lua_pop(L, (int) num);
    

}

JNIEXPORT void JNICALL Java_io_nondev_nonlua_Lua_jniPushValue(JNIEnv* env, jclass clazz, jobject cptr, jint index) {


//@line:292

        lua_State * L = nonlua_getstate(env, cptr);

        lua_pushvalue(L, (int) index);
    

}

JNIEXPORT void JNICALL Java_io_nondev_nonlua_Lua_jniRemove(JNIEnv* env, jclass clazz, jobject cptr, jint index) {


//@line:298

        lua_State * L = nonlua_getstate(env, cptr);

        lua_remove(L, (int) index);
    

}

JNIEXPORT void JNICALL Java_io_nondev_nonlua_Lua_jniInsert(JNIEnv* env, jclass clazz, jobject cptr, jint index) {


//@line:304

        lua_State * L = nonlua_getstate(env, cptr);

        lua_insert(L, (int) index);
    

}

JNIEXPORT void JNICALL Java_io_nondev_nonlua_Lua_jniReplace(JNIEnv* env, jclass clazz, jobject cptr, jint index) {


//@line:310

        lua_State * L = nonlua_getstate(env, cptr);

        lua_replace(L, (int) index);
    

}

JNIEXPORT void JNICALL Java_io_nondev_nonlua_Lua_jniConcat(JNIEnv* env, jclass clazz, jobject cptr, jint index) {


//@line:316

        lua_State * L = nonlua_getstate(env, cptr);

        lua_concat(L, (int) index);
    

}

static inline jstring wrapped_Java_io_nondev_nonlua_Lua_jniGsub
(JNIEnv* env, jclass clazz, jobject cptr, jstring obj_s, jstring obj_p, jstring obj_r, char* s, char* p, char* r) {

//@line:322

        lua_State * L = nonlua_getstate(env, cptr);

        const char * sub = luaL_gsub(L, s, p, r);
        return env->NewStringUTF(sub);
    
}

JNIEXPORT jstring JNICALL Java_io_nondev_nonlua_Lua_jniGsub(JNIEnv* env, jclass clazz, jobject cptr, jstring obj_s, jstring obj_p, jstring obj_r) {
	char* s = (char*)env->GetStringUTFChars(obj_s, 0);
	char* p = (char*)env->GetStringUTFChars(obj_p, 0);
	char* r = (char*)env->GetStringUTFChars(obj_r, 0);

	jstring JNI_returnValue = wrapped_Java_io_nondev_nonlua_Lua_jniGsub(env, clazz, cptr, obj_s, obj_p, obj_r, s, p, r);

	env->ReleaseStringUTFChars(obj_s, s);
	env->ReleaseStringUTFChars(obj_p, p);
	env->ReleaseStringUTFChars(obj_r, r);

	return JNI_returnValue;
}

JNIEXPORT jint JNICALL Java_io_nondev_nonlua_Lua_jniLen(JNIEnv* env, jclass clazz, jobject cptr, jint index) {


//@line:329

        lua_State * L = nonlua_getstate(env, cptr);

        return (jint) lua_objlen(L, (int) index);
    

}

JNIEXPORT jint JNICALL Java_io_nondev_nonlua_Lua_jniEqual(JNIEnv* env, jclass clazz, jobject cptr, jint index1, jint index2) {


//@line:335

        lua_State * L = nonlua_getstate(env, cptr);

        return (jint) lua_equal(L, (int) index1, (int) index2);
    

}

JNIEXPORT jint JNICALL Java_io_nondev_nonlua_Lua_jniNext(JNIEnv* env, jclass clazz, jobject cptr, jint index) {


//@line:341

        lua_State * L = nonlua_getstate(env, cptr);

        return (jint) lua_next(L, (int) index);
    

}

static inline jint wrapped_Java_io_nondev_nonlua_Lua_jniError
(JNIEnv* env, jclass clazz, jobject cptr, jstring obj_msg, char* msg) {

//@line:347

        lua_State * L = nonlua_getstate(env, cptr);

        return (jint) luaL_error(L, msg);
    
}

JNIEXPORT jint JNICALL Java_io_nondev_nonlua_Lua_jniError(JNIEnv* env, jclass clazz, jobject cptr, jstring obj_msg) {
	char* msg = (char*)env->GetStringUTFChars(obj_msg, 0);

	jint JNI_returnValue = wrapped_Java_io_nondev_nonlua_Lua_jniError(env, clazz, cptr, obj_msg, msg);

	env->ReleaseStringUTFChars(obj_msg, msg);

	return JNI_returnValue;
}

JNIEXPORT void JNICALL Java_io_nondev_nonlua_Lua_jniWhere(JNIEnv* env, jclass clazz, jobject cptr, jint lvl) {


//@line:353

        lua_State * L = nonlua_getstate(env, cptr);

        luaL_where(L, (int) lvl);
    

}

JNIEXPORT jint JNICALL Java_io_nondev_nonlua_Lua_jniType(JNIEnv* env, jclass clazz, jobject cptr, jint index) {


//@line:359

        lua_State * L = nonlua_getstate(env, cptr);

        return (jint) lua_type(L, (int) index);
    

}

JNIEXPORT jstring JNICALL Java_io_nondev_nonlua_Lua_jniTypeName(JNIEnv* env, jclass clazz, jobject cptr, jint type) {


//@line:365

        lua_State * L = nonlua_getstate(env, cptr);
        
        return env->NewStringUTF(lua_typename(L, (int) type));
    

}

JNIEXPORT jint JNICALL Java_io_nondev_nonlua_Lua_jniRef(JNIEnv* env, jclass clazz, jobject cptr, jint index) {


//@line:371

        lua_State * L = nonlua_getstate(env, cptr);

        return (jint) luaL_ref(L, (int) index);
    

}

JNIEXPORT void JNICALL Java_io_nondev_nonlua_Lua_jniUnRef(JNIEnv* env, jclass clazz, jobject cptr, jint index, jint ref) {


//@line:377

        lua_State * L = nonlua_getstate(env, cptr);

        luaL_unref(L, (int) index, (int) ref);
    

}

JNIEXPORT void JNICALL Java_io_nondev_nonlua_Lua_jniCall(JNIEnv* env, jclass clazz, jobject cptr, jint nArgs, jint nResults) {


//@line:383

        lua_State * L = nonlua_getstate(env, cptr);

        lua_call(L, (int) nArgs, (int) nResults);
    

}

JNIEXPORT jint JNICALL Java_io_nondev_nonlua_Lua_jniPcall(JNIEnv* env, jclass clazz, jobject cptr, jint nArgs, jint nResults, jint errFunc) {


//@line:389

        lua_State * L = nonlua_getstate(env, cptr);

        return (jint) lua_pcall(L, (int) nArgs, (int) nResults, (int) errFunc);
    

}

JNIEXPORT void JNICALL Java_io_nondev_nonlua_Lua_jniNewTable(JNIEnv* env, jclass clazz, jobject cptr) {


//@line:395

        lua_State * L = nonlua_getstate(env, cptr);

        lua_newtable(L);
    

}

JNIEXPORT void JNICALL Java_io_nondev_nonlua_Lua_jniGetTable(JNIEnv* env, jclass clazz, jobject cptr, jint index) {


//@line:401

        lua_State * L = nonlua_getstate(env, cptr);

        lua_gettable(L, (int) index);
    

}

JNIEXPORT void JNICALL Java_io_nondev_nonlua_Lua_jniSetTable(JNIEnv* env, jclass clazz, jobject cptr, jint index) {


//@line:407

        lua_State * L = nonlua_getstate(env, cptr);

        lua_settable(L, (int) index);
    

}

static inline jint wrapped_Java_io_nondev_nonlua_Lua_jniNewMetatable
(JNIEnv* env, jclass clazz, jobject cptr, jstring obj_name, char* name) {

//@line:413

        lua_State * L = nonlua_getstate(env, cptr);

        return (jint) luaL_newmetatable(L, name);
    
}

JNIEXPORT jint JNICALL Java_io_nondev_nonlua_Lua_jniNewMetatable(JNIEnv* env, jclass clazz, jobject cptr, jstring obj_name) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);

	jint JNI_returnValue = wrapped_Java_io_nondev_nonlua_Lua_jniNewMetatable(env, clazz, cptr, obj_name, name);

	env->ReleaseStringUTFChars(obj_name, name);

	return JNI_returnValue;
}

JNIEXPORT jint JNICALL Java_io_nondev_nonlua_Lua_jniGetMetatable(JNIEnv* env, jclass clazz, jobject cptr, jint index) {


//@line:419

        lua_State * L = nonlua_getstate(env, cptr);
        
        return (jint) lua_getmetatable(L, (int) index);
    

}

JNIEXPORT void JNICALL Java_io_nondev_nonlua_Lua_jniGetMetatableStr(JNIEnv* env, jclass clazz, jobject cptr, jstring obj_name) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);


//@line:425

        lua_State * L = nonlua_getstate(env, cptr);
        
        luaL_getmetatable(L, name);
    
	env->ReleaseStringUTFChars(obj_name, name);

}

JNIEXPORT jint JNICALL Java_io_nondev_nonlua_Lua_jniSetMetatable(JNIEnv* env, jclass clazz, jobject cptr, jint index) {


//@line:431

        lua_State * L = nonlua_getstate(env, cptr);

        return (jint) lua_setmetatable(L, (int) index);
    

}

static inline jint wrapped_Java_io_nondev_nonlua_Lua_jniCallmeta
(JNIEnv* env, jclass clazz, jobject cptr, jint index, jstring obj_field, char* field) {

//@line:437

        lua_State * L = nonlua_getstate(env, cptr);

        return (jint) luaL_callmeta(L, (int) index, field);
    
}

JNIEXPORT jint JNICALL Java_io_nondev_nonlua_Lua_jniCallmeta(JNIEnv* env, jclass clazz, jobject cptr, jint index, jstring obj_field) {
	char* field = (char*)env->GetStringUTFChars(obj_field, 0);

	jint JNI_returnValue = wrapped_Java_io_nondev_nonlua_Lua_jniCallmeta(env, clazz, cptr, index, obj_field, field);

	env->ReleaseStringUTFChars(obj_field, field);

	return JNI_returnValue;
}

static inline jint wrapped_Java_io_nondev_nonlua_Lua_jniGetmeta
(JNIEnv* env, jclass clazz, jobject cptr, jint index, jstring obj_field, char* field) {

//@line:443

        lua_State * L = nonlua_getstate(env, cptr);

        return (jint) luaL_getmetafield(L, (int) index, field);
    
}

JNIEXPORT jint JNICALL Java_io_nondev_nonlua_Lua_jniGetmeta(JNIEnv* env, jclass clazz, jobject cptr, jint index, jstring obj_field) {
	char* field = (char*)env->GetStringUTFChars(obj_field, 0);

	jint JNI_returnValue = wrapped_Java_io_nondev_nonlua_Lua_jniGetmeta(env, clazz, cptr, index, obj_field, field);

	env->ReleaseStringUTFChars(obj_field, field);

	return JNI_returnValue;
}

JNIEXPORT void JNICALL Java_io_nondev_nonlua_Lua_jniMove(JNIEnv* env, jclass clazz, jobject cptr, jobject to, jint index) {


//@line:449

        lua_State * fr = nonlua_getstate(env, cptr);
        lua_State * t  = nonlua_getstate(env, to);

        lua_xmove(fr, t, (int) index);
    

}

JNIEXPORT jint JNICALL Java_io_nondev_nonlua_Lua_jniYield(JNIEnv* env, jclass clazz, jobject cptr, jint nResults) {


//@line:456

        lua_State * L = nonlua_getstate(env, cptr);

        return (jint) lua_yield(L, (int) nResults);
    

}

JNIEXPORT jint JNICALL Java_io_nondev_nonlua_Lua_jniResume(JNIEnv* env, jclass clazz, jobject cptr, jint nArgs) {


//@line:462

        lua_State * L = nonlua_getstate(env, cptr);

        return (jint) lua_resume(L, (int) nArgs);
    

}

JNIEXPORT jint JNICALL Java_io_nondev_nonlua_Lua_jniStatus(JNIEnv* env, jclass clazz, jobject cptr) {


//@line:468

        lua_State * L = nonlua_getstate(env, cptr);

        return (jint) lua_status(L);
    

}

