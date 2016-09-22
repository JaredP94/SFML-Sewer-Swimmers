#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <map>
#include <memory>

using std::map;

/**
* AssetManager template class - manages loading of most assets.
* This template class can load all required assets such as textures, shaders, sounds, etc. However it is incapable of loading in music due to how SFML manages music playback.
*/
template<typename Asset, typename Identity> 
class AssetManager
{
public:
	/**
	* Loads required asset from file destination.
	* @param id is the EntityList key used to reference the asset for later use.
	* @param filePath is the string containing the required file path to locate the asset.
	*/
	void loadAsset(Identity id, const std::string& filePath);
	/**
	* Retrives required asset related to the entered EntityList key.
	* @param id is the EntityList key which is used to search for the required asset.
	* @return is a reference to asset which matches the entered EntityList key.
	*/
	Asset& getAsset(Identity id);
	
private:
	/**
	* Allocates a unique pointer to an asset in a map of assets.
	* @param id is the EntityList key which is used to search for the required asset.
	* @param asset_ptr is a reference to the asset based on the entered EntityList key.
	*/
	void addAsset(Identity id, std::unique_ptr<Asset>& asset_ptr);
	map<Identity, std::unique_ptr<Asset>> _assets;
};
#include "assetManager.tpp"
#endif