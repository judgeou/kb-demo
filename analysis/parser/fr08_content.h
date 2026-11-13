#pragma once
#include <cstdint>
#include <vector>
#include <string>
#include <array>
namespace fr08 {
struct Node{uint32_t id;uint8_t group,op;int8_t flags;uint8_t type,count,aux;uint16_t reserved;int32_t linkA,linkB;uint32_t parameterOffset;};
struct Event{uint8_t flags,kind;uint16_t group,groupFlags;float start,end,duration;};
struct Key{int16_t time;float value;std::array<float,4> coefficients={};};
struct Channel{uint16_t node,group;uint8_t field,mode;std::vector<Key> keys;};
struct CustomTable{uint8_t tag;std::vector<uint8_t> data;};
struct Content{
 std::vector<Node> nodes;std::vector<uint32_t> textureRoots,sceneRoots;std::vector<Event> events;std::vector<Channel> channels;std::vector<float> parameters;std::vector<std::string> strings;std::vector<CustomTable> tables;
 uint32_t sourceBegin=0,sourceEnd=0,keyCount=0,groupCount=0;
 static Content parse(const std::vector<uint8_t>&image,uint32_t offset=0x45010);
 void prepareCurves();float evaluate(size_t channel,float normalizedTime)const;
};
}
