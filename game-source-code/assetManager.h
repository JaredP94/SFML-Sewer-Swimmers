#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <map>
#include <memory>

using std::map;

template<typename Asset, typename Identity> 
class AssetManager
{
public:
	void loadAsset(Identity id, const std::string& filePath);
	Asset& getAsset(Identity id);
	
private:
	void addAsset(Identity id, std::unique_ptr<Asset>& asset_ptr);
	map<Identity, std::unique_ptr<Asset>> _assets;
};
#include "assetManager.tpp"
#endif