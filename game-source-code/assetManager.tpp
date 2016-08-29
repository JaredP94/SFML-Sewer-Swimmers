template<typename Asset, typename Identity>
void AssetManager<Asset, Identity>::loadAsset(Identity id, const string& filePath)
{
	auto asset_ptr = make_unique<Asset>(Asset{});
	if(!(asset_ptr->loadFromFile(filePath)))	
	{
		throw runtime_error("AssetManager::load - Failed to load: " + filePath);
	}
	addAsset(id, asset_ptr);
}

template<typename Asset, typename Identity>
template<typename Parameter>
void AssetManager<Asset, Identity>::loadAsset(Identity id, const string& filePath, const Parameter& optionalParameter)
{
	auto asset_ptr = make_unique<Asset>(Asset{});
	if(!(asset_ptr->loadFromFile(filePath, optionalParameter)))
	{		
		throw runtime_error("AssetManager::load - Failed to load: " + filePath);
	}
	addAsset(id, asset_ptr);
}

template <typename Asset, typename Identity>
Asset& AssetManager<Asset, Identity>::get(Identity id)
{
	auto found_ptr = _assets.find(id);
	if (found_ptr == _assets.end()) throw logic_error("AssetManager::get - could not find resource corresponding to given id");
	return *found_ptr->second;
}

template <typename Asset, typename Identity>
const Asset& AssetManager<Asset, Identity>::get(Identity id) const
{	
	auto found_ptr = _assets.find(id);	
	if (found_ptr == _assets.end()) throw logic_error("AssetManager::get - could not find resource corresponding to given id");
	return *found_ptr->second;
}

template <typename Asset, typename Identity>
void AssetManager<Asset, Identity>::addAsset(Identity id, unique_ptr<Asset>& asset_ptr)
{		
	auto inserted = _assets.insert(make_pair(id, move(asset_ptr)));
	if(!(inserted.second)) throw logic_error("AssetManager::addAsset - resource with given id already added");
}