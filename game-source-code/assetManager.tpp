template<typename Asset, typename Identity>
void AssetManager<Asset, Identity>::loadAsset(Identity id, const std::string& filePath)
{
	auto asset_ptr = std::make_unique<Asset>(Asset{});
	if(!(asset_ptr->loadFromFile(filePath)))	
	{
		throw std::runtime_error("AssetManager::loadAsset - Unable to load: " + filePath);
	}
	addAsset(id, asset_ptr);
}

template <typename Asset, typename Identity>
Asset& AssetManager<Asset, Identity>::getAsset(Identity id)
{
	auto search_ptr = _assets.find(id);
	if (search_ptr == _assets.end()) 
	{
		throw std::logic_error("AssetManager::get - id specific resource not found");
	}
	return *search_ptr->second;
}

template <typename Asset, typename Identity>
void AssetManager<Asset, Identity>::addAsset(Identity id, std::unique_ptr<Asset>& asset_ptr)
{		
	auto inserted = _assets.insert(std::make_pair(id, std::move(asset_ptr)));
	if(!(inserted.second))
	{
		throw std::logic_error("AssetManager::addAsset - id-specific resource previously added");
	}
}