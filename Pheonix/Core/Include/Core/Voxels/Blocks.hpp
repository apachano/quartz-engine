// Copyright 2019 Genten Studios
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors
// may be used to endorse or promote products derived from this software without
// specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#pragma once

#include <Quartz/Math/Math.hpp>
#include <Quartz/Utilities/Singleton.hpp>

#include <string>
#include <vector>
#include <list>
#include <unordered_map>

namespace pheonix
{
	namespace voxels
	{
		/// @brief Texture atlas for a block
		class BlockTextureAtlas
		{
		public:
			typedef int           SpriteID;
			const static SpriteID INVALID_SPRITE = -1;

			BlockTextureAtlas(std::size_t spriteWidth,
			                  std::size_t spriteHeight);
			BlockTextureAtlas();
			~BlockTextureAtlas();

			void addTextureFile(const char* texturefilepath);
			void patch();
			void setSpriteWidth(std::size_t w);
			void setSpriteHeight(std::size_t h);

			std::size_t getSpriteWidth() const { return m_spriteWidth; }
			std::size_t getSpriteHeight() const { return m_spriteHeight; }
			SpriteID    getSpriteIDFromFilepath(const char* filepath);

			std::size_t getPatchedTextureWidth() const
			{
				return m_patchedTextureWidth;
			}

			std::size_t getPatchedTextureHeight() const
			{
				return m_patchedTextureHeight;
			}

			unsigned char* getPatchedTextureData() const
			{
				return m_patchedTextureData;
			}

			qz::RectAABB getSpriteFromID(SpriteID spriteId) const;

		private:
			std::unordered_map<std::string, SpriteID> m_textureIDMap;
			std::size_t    m_spriteWidth, m_spriteHeight;
			unsigned char* m_patchedTextureData;

			std::size_t m_patchedTextureWidth, m_patchedTextureHeight;
		};

		enum class BlockTypeCategory
		{
			AIR,
			SOLID,
			LIQUID
		};

		/// @brief Stores universal definition of a block
		struct RegisteredBlock
		{
			/// @brief Stores unique ID to identify block for use in memory,
			/// should match location in registry
			int blockId;
			/// @brief Stores Unique name for use duing saving, should be in
			/// format mod:name eg "core:dirt"
			std::string uniqueName;
			/// @brief Stores human readable name for output to player ex "dirt"
			std::string displayName;

			RegisteredBlock(std::string unique, int id, std::string display);

			~RegisteredBlock();
		};

		/// @brief Stores universal block definitions
		class BlockRegistry
		{
		private:
			std::vector<RegisteredBlock> Blocks;
			int i;

		public:
			BlockRegistry();
			~BlockRegistry();

			/// @brief Registers a block in the registry
			int registerBlock(const std::string& UniqueName, const std::string& DisplayName);
			const std::string& getDisplayName(int blockId);
			int         getBlockId(const std::string& UniqueName);
		};

		/// @breif Metadata for a block, this is only created if a block needs
		/// to store more data than what is universal (eg: we wont create this
		/// for each dirt block)
		class Block
		{
		public:
			Block(const std::string& UniqueName, int BlockId, const std::string& DisplayName);
			~Block();
		};

	} // namespace voxels

} // namespace pheonix