template<typename Asset, typename Identity>
void AssetManager<Asset, Identity>::loadAsset(Identity id, const string& filePath)
{
	auto asset_ptr = make_unique<Asset>(Asset{});
	if(!(asset_ptr->loadFromFile(filePath)))	
	{
		throw runtime_error("AssetManager::load - Unable to load: " + filePath);
	}
	addAsset(id, asset_ptr);
}

template <typename Asset, typename Identity>
Asset& AssetManager<Asset, Identity>::get(Identity id)
{
	auto search_ptr = _assets.find(id);
	if (search_ptr == _assets.end()) 
	{
		throw logic_error("AssetManager::get - id specific resource not found");
	}
	return *search_ptr->second;
}

template <typename Asset, typename Identity>
void AssetManager<Asset, Identity>::addAsset(Identity id, unique_ptr<Asset>& asset_ptr)
{		
	auto inserted = _assets.insert(make_pair(id, move(asset_ptr)));
	if(!(inserted.second))
	{
		throw logic_error("AssetManager::addAsset - id-specific resource previously added");
	}
}