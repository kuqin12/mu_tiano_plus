/** @file
  Provides FMP capsule dependency check services when updating the firmware
  image of a FMP device.

  Copyright (c) 2020, Intel Corporation. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/
#include <PiDxe.h>
#include <Library/FmpDependencyCheckLib.h>

/**
  Check dependency for firmware update.

  @param[in]  ImageTypeId        Image Type Id.
  @param[in]  Version            New version.
  @param[in]  Dependencies       Fmp dependency.
  @param[in]  DependenciesSize   Size, in bytes, of the Fmp dependency.

  @retval  TRUE    Dependencies are satisfied.
  @retval  FALSE   Dependencies are unsatisfied or dependency check fails.

**/
BOOLEAN
EFIAPI
CheckFmpDependency (
  IN  CONST EFI_GUID                ImageTypeId,
  IN  CONST UINT32                  Version,
  IN  CONST EFI_FIRMWARE_IMAGE_DEP  *Dependencies,    OPTIONAL
  IN  CONST UINT32                  DependenciesSize  OPTIONAL
  )
{
  return TRUE;
}

/**
  Save dependency to Fmp device.

  @param[in]  Depex       Fmp dependency.
  @param[in]  DepexSize   Size, in bytes, of the Fmp dependency.

  @retval  EFI_SUCCESS       Save Fmp dependency succeeds.
  @retval  EFI_UNSUPPORTED   Save Fmp dependency is not supported.
  @retval  Others            Save Fmp dependency fails.

**/
EFI_STATUS
EFIAPI
SaveFmpDependency (
  IN EFI_FIRMWARE_IMAGE_DEP  *Depex,
  IN UINT32                  DepexSize
  )
{
  return EFI_UNSUPPORTED;
}

/**
  Get dependency from the Fmp device.

  @param[out]  DepexSize   Size, in bytes, of the dependency.

  @retval  The pointer to dependency.
  @retval  NULL

**/
EFI_FIRMWARE_IMAGE_DEP*
EFIAPI
GetFmpDependency (
  OUT UINT32  *DepexSize  OPTIONAL
  )
{
  return NULL;
}