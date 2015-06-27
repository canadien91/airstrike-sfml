
#ifndef __RESOURCE_HOLDER_H__
#define __RESOURCE_HOLDER_H__

#include <cassert>
#include <map>
#include <memory>
#include <stdexcept>
#include <string>

#include <SFML/Graphics.hpp>

template <typename Resource, typename Identifier>
class AResourceHolder {
public:
    void            LoadResourceFromFile( Identifier id, const std::string& filename );

    template <typename Parameter>
    void            LoadResourceFromFile(
        Identifier id,
        const std::string& filename,
        const Parameter& second_param
    );
    Resource&       GetResource( Identifier id );
    const Resource& GetResource( Identifier id ) const;

private:
    std::map<Identifier, Resource*> resource_map;

    void InsertResource( Identifier id, std::unique_ptr<Resource> resource );
};

#include "ResourceHolder.inl"

#endif
