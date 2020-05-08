/** @file
  Fmp Capsule Dependency support functions for Firmware Management Protocol based
  firmware updates.

  Copyright (c) 2020, Intel Corporation. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef __FMP_DEPENDENCY_LIB__
#define __FMP_DEPENDENCY_LIB__

#include <PiDxe.h>
#include <Protocol/FirmwareManagement.h>

//
// Data struct to store FMP ImageType and version for dependency check.
//
typedef struct {
  EFI_GUID ImageTypeId;
  UINT32   Version;
} FMP_DEPEX_CHECK_VERSION_DATA;

/**
  Validate the dependency expression and output its size.

  @param[in]   Dependencies   Pointer to the EFI_FIRMWARE_IMAGE_DEP.
  @param[in]   MaxDepexSize   Max size of the dependency.
  @param[out]  DepexSize      Size of dependency.

  @retval TRUE    The capsule is valid.
  @retval FALSE   The capsule is invalid.

**/
BOOLEAN
EFIAPI
ValidateDependency (
  IN  EFI_FIRMWARE_IMAGE_DEP  *Dependencies,
  IN  CONST UINTN             MaxDepexSize,
  OUT UINT32                  *DepexSize
  );

/**
  Get the size of dependencies. Assume the dependencies is validated before
  calling this function.

  @param[in]  Dependencies   Pointer to the EFI_FIRMWARE_IMAGE_DEP.

  @retval  The size of dependencies.

**/
UINTN
EFIAPI
GetDependencySize (
  IN CONST EFI_FIRMWARE_IMAGE_DEP  *Dependencies
  );

/**
  Get dependency from firmware image.

  @param[in]  Image       Points to the firmware image.
  @param[in]  ImageSize   Size, in bytes, of the firmware image.
  @param[out] DepexSize   Size, in bytes, of the dependency.

  @retval  The pointer to dependency.
  @retval  Null

**/
EFI_FIRMWARE_IMAGE_DEP*
EFIAPI
GetImageDependency (
  IN  EFI_FIRMWARE_IMAGE_AUTHENTICATION  *Image,
  IN  UINTN                              ImageSize,
  OUT UINT32                             *DepexSize
  );

/**
  Evaluate the dependencies. The caller must search all the Fmp instances and
  gather their versions into FmpVersions parameter. If there is PUSH_GUID opcode
  in dependency expression with no FmpVersions provided, the dependency will
  evaluate to FALSE.

  @param[in]   Dependencies       Dependency expressions.
  @param[in]   DependenciesSize   Size of Dependency expressions.
  @param[in]   FmpVersions        Array of Fmp ImageTypeId and version. This
                                  parameter is optional and can be set to NULL.
  @param[in]   FmpVersionsCount   Element count of the array. When FmpVersions
                                  is NULL, FmpVersionsCount must be 0.

  @retval TRUE    Dependency expressions evaluate to TRUE.
  @retval FALSE   Dependency expressions evaluate to FALSE.

**/
BOOLEAN
EFIAPI
EvaluateDependency (
  IN CONST EFI_FIRMWARE_IMAGE_DEP        *Dependencies,
  IN CONST UINTN                         DependenciesSize,
  IN CONST FMP_DEPEX_CHECK_VERSION_DATA  *FmpVersions      OPTIONAL,
  IN CONST UINTN                         FmpVersionsCount  OPTIONAL
  );

#endif