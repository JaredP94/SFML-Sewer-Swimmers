#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <iostream>
#include <map>
#include <memory>

using std::string;
using std::map;
using std::make_pair;
using std::move;
using std::unique_ptr;
using std::make_unique;
using std::runtime_error;
using std::logic_error;

template<typename Asset, typename Identity> 
class AssetManager
{
public:
	void loadAsset(Identity id, const string& filePath);
	template<typename Parameter>
	void loadAsset(Identity id, const string& filePath, const Parameter& optionalParameter);
	Asset& get(Identity id);
	const Asset& get(Identity id) const;
	
private:
	void addAsset(Identity id, unique_ptr<Asset>& asset_ptr);
	map<Identity, unique_ptr<Asset>> _assets;
};
#include "assetManager.tpp"
#endif