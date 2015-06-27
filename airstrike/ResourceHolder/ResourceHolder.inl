
template <typename Resource, typename Identifier>
void
AResourceHolder<Resource, Identifier>::LoadResourceFromFile(
    Identifier id,
    const std::string& filename
) {
    Resource* resource( new Resource() );
    if ( !resource->loadFromFile( filename ) ) {
        throw std::runtime_error(
            "ResourceHolder::LoadResourceFromFile - Failed to load " + filename
        );
    }
    this->InsertResource( id, std::move( resource ) );
}

template <typename Resource, typename Identifier>
template <typename Parameter>
void
AResourceHolder<Resource, Identifier>::LoadResourceFromFile(
   Identifier id,
   const std::string& filename,
   const Parameter& second_param
) {
   std::unique_ptr<Resource> resource( new Resource() );
   if ( !resource->loadFromFile( filename, second_param ) ) {
       throw std::runtime_error(
           "ResourceHolder::LoadResourceFromFile - Failed to load " + filename
       );
   }
   this->InsertResource( id, std::move( resource ) );
}

template <typename Resource, typename Identifier>
const Resource&
AResourceHolder<Resource, Identifier>::GetResource( Identifier id ) const {
   auto found = this->resource_map.find( id );
   assert( found != this->resource_map.end() );
   return *found->second;
}

template <typename Resource, typename Identifier>
void
AResourceHolder<Resource, Identifier>::InsertResource(
   Identifier id,
   std::unique_ptr<Resource> resource
) {
   auto inserted = this->resource_map.insert( std::make_pair( id, std::move( resource ) ) );
   assert( inserted.second );
}
